<?php
// Nathon Iadimarco
// 11/27/2024
// Introduction to Database System Design
// Final Project Application Implementation
// deposit.php

session_start();
include('config.php');
$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Assuming user is logged in and their account information is available in session
$accountID = $_SESSION['AccountID'];
$balance = $_SESSION['Balance'];

$sql = "SELECT Balance FROM Accounts WHERE AccountID = '$accountID'";
$result = mysqli_query($conn, $sql);
$row = mysqli_fetch_assoc($result);

$balance = $row['Balance'] ?? 0.00; // Default to 0.00 if no balance is found

$depositSuccess = false;
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['amount'])) {
    $amount = floatval($_POST['amount']);
    
    if ($amount > 0) {
        $oldBalance = $balance;
        $balance += $amount;
        $newBalance = $balance;
        $depositSuccess = true;
        $transactionType = 'Deposit';
        $description = 'Manual balance deposit.';  // Adding description
        $amountSign = ($amount >= 0) ? "+" : "-"; // Used to add + or - based on transaction
        $transactionDate = date("Y-m-d H:i:s"); // Current timestamp for transaction date

        // Inserting the transaction into the Transactions table
        $insertTransactionSql = "INSERT INTO Transactions (AccountID, TransactionType, Amount, OldBalance, NewBalance, TransactionDate, Description)
                                 VALUES ('$accountID', '$transactionType', '$amount', '$oldBalance', '$newBalance', '$transactionDate', '$description')";

        if (mysqli_query($conn, $insertTransactionSql)) {
            // Update balance in the Accounts table
            $updateBalanceSql = "UPDATE Accounts SET Balance = '$newBalance' WHERE AccountID = '$accountID'";
            if (mysqli_query($conn, $updateBalanceSql)) {
                // Update session balance
                $_SESSION['Balance'] = $newBalance;
            } else {
                echo "Error updating balance: " . mysqli_error($conn);
            }
        } else {
            echo "Error logging transaction: " . mysqli_error($conn);
        }
    } else {
        echo "Invalid deposit amount.";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DataBank - Deposit Funds</title>
    <link rel="stylesheet" href="styles.css"> <!-- Link to your existing CSS -->
</head>
<body>
    <!-- Top Navigation Bar -->
    <div class="navbar">
        <a href="home.php" class="navbar-brand">DataBank</a>
        <a href="DataBank.php" class="logout">Logout</a>
    </div>

    <!-- Main Container -->
    <div class="container">
        <h1 class="title">Deposit Funds</h1>

        <!-- Display current balance -->
        <p class="description">Your current balance: $<?php echo number_format($balance, 2); ?></p>

        <?php if (isset($depositSuccess) && $depositSuccess): ?>
            <div class="success-message">Deposit successful! New balance: $<?php echo number_format($newBalance, 2); ?></div>
        <?php elseif (isset($depositError)): ?>
            <div class="error"><?php echo $depositError; ?></div>
        <?php endif; ?>

        <!-- Deposit Form -->
        <form method="POST" class="form-container">
            <input type="number" name="amount" placeholder="Enter amount to deposit" required>
            <input type="submit" value="Deposit" class="submit-button">
        </form>

        <a href="home.php" class="back-button">Back to Home</a>
    </div>
</body>
</html>
