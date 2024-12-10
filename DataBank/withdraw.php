<?php
// Nathon Iadimarco
// 11/27/2024
// Introduction to Database System Design
// Final Project Application Implementation
// withdraw.php

session_start();
include('config.php');
$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
$accountID = $_SESSION['AccountID'];
$balance = $_SESSION['Balance'];

$sql = "SELECT Balance FROM Accounts WHERE AccountID = '$accountID'";
$result = mysqli_query($conn, $sql);
$row = mysqli_fetch_assoc($result);

$balance = $row['Balance'] ?? 0.00; // Default to 0.00 if no balance is found

// Placeholder for withdraw functionality
$withdrawSuccess = false;
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['amount'])) {
    $amount = floatval($_POST['amount']);
    
    if ($amount > 0 && $amount <= $balance) {
        $oldBalance = $balance;
        $balance -= $amount;
        $newBalance = $balance;
        $withdrawSuccess = true;
        $transactionType = 'Withdrawal';
        $description = 'Manual balance withdrawal.';  // Withdrawal description
        $amountSign = ($amount >= 0) ? "+" : "-";
        $transactionDate = date("Y-m-d H:i:s"); // Timestamp

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
         echo "Insufficient balance or invalid amount.";
     }
 }
 ?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DataBank - Withdraw Funds</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <!-- Top Navigation Bar -->
    <div class="navbar">
        <a href="home.php" class="navbar-brand">DataBank</a>
        <a href="DataBank.php" class="logout">Logout</a>
    </div>

    <!-- Main Container -->
    <div class="container">
        <h1 class="title">Withdraw Funds</h1>

<!-- Main Container -->
<div class="container">    
    <!-- Display current balance -->
    <p class="description">Your current balance: $<?php echo number_format($balance, 2); ?></p>
</div>
        <?php if (isset($withdrawSuccess) && $withdrawSuccess): ?>
            <div class="success-message">Withdrawal successful! New balance: $<?php echo number_format($newBalance, 2); ?></div>
        <?php elseif (isset($withdrawError)): ?>
            <div class="error"><?php echo $withdrawError; ?></div>
        <?php endif; ?>

        <!-- Withdrawal Form -->
        <form method="POST" action="withdraw.php" class="form-container">
            <input type="number" name="amount" placeholder="Enter amount to withdraw" required>
            <input type="submit" value="Withdraw" class="submit-button">
        </form>

        <a href="home.php" class="back-button">Back to Home</a>
    </div>
</body>
</html>
