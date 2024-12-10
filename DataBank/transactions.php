<?php
// Nathon Iadimarco
// 11/27/2024
// Introduction to Database System Design
// Final Project Application Implementation
// transactions.php

session_start();
include('config.php');
$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Fetch the AccountID from session (logged-in user's account ID)
$accountID = $_SESSION['AccountID'] ?? null;
$description = $_POST['description'];

if (!$accountID) {
    die("User not logged in.");
}

// Fetch current balance for specific account
$sql = "SELECT Balance FROM Accounts WHERE AccountID = '$accountID'";
$result = mysqli_query($conn, $sql);
$row = mysqli_fetch_assoc($result);
$balance = $row['Balance'] ?? 0.00;

// Check if form is submitted
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $newBalance = (float)$_POST['balance']; // Get the new balance from the form
    $_SESSION['balance'] = $newBalance; // Update balance in session (simulating database update)
    
    
    // Keeping track of the previous balance before change
    $oldBalance = $balance;

    // Update the balance in the database
    $updateSql = "UPDATE Accounts SET Balance = '$newBalance' WHERE AccountID = '$accountID'";
    if (mysqli_query($conn, $updateSql)) {
        // Log the transaction into the Transactions table
        $transactionType = ($newBalance > $oldBalance) ? 'Deposit' : 'Withdrawal';
        
        $amount = $newBalance - $oldBalance; // Getting amount of transaction

        // Determine the sign for the amount
        $amountSign = ($amount >= 0) ? "+" : "-";
        
        // Insert the transaction record
        $transactionDate = date("Y-m-d H:i:s");

        $insertTransactionSql = "INSERT INTO Transactions (AccountID, TransactionType, Amount, OldBalance, NewBalance, TransactionDate, Description)
                                 VALUES ('$accountID', '$transactionType', '$amount', '$oldBalance', '$newBalance', '$transactionDate', '$description')";

        if (mysqli_query($conn, $insertTransactionSql)) {
            // Success, update session balance and redirect
            $_SESSION['balance'] = $newBalance; // Update session balance
            header("Location: transactions.php?success=1");
            exit();
        } else {
            echo "Error logging transaction: " . mysqli_error($conn);
        }
    } else {
        echo "Error updating balance: " . mysqli_error($conn);
    }
}

// Fetching transaction history for specific account
$sql = "SELECT TransactionID, TransactionType, Amount, OldBalance, NewBalance, TransactionDate, Description 
        FROM Transactions WHERE AccountID = ? ORDER BY TransactionDate DESC";
$stmt = $conn->prepare($sql);
if (!$stmt) {
    die("Query preparation failed: " . $conn->error);
}
$stmt->bind_param("i", $accountID); // Bind AccountID as integer
$stmt->execute();
$result = $stmt->get_result();

// Store transactions in an array
$transactions = [];
while ($row = $result->fetch_assoc()) {
    $transactions[] = $row;
}

$stmt->close();
$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DataBank - Transaction History</title>
    <link rel="stylesheet" href="styles.css"> <!-- Link to your existing CSS -->
</head>
<body class="transactions-page">
    <!-- Top Navigation Bar -->
    <div class="navbar">
        <a href="home.php" class="navbar-brand">DataBank</a>
        <a href="DataBank.php" class="logout">Logout</a>
    </div>

    <!-- Main Container -->
    <div class="container">
        <h1 class="title">Transaction History</h1>

        <p class="description">Below are your recent transactions:</p>

        <!-- Table Wrapper for Centering -->
        <div class="table-wrapper">
            <table class="transaction-table">
                <tr>
                    <th>Transaction ID</th>
                    <th>Transaction Type</th>
                    <th>Amount</th>
                    <th>Old Balance</th>
                    <th>New Balance</th>
                    <th>Transaction Date</th>
                    <th>Description</th>
                </tr>
                <?php foreach ($transactions as $transaction): ?>
                <tr>
                    <td><?php echo htmlspecialchars($transaction['TransactionID']); ?></td>
                    <td><?php echo htmlspecialchars($transaction['TransactionType']); ?></td>
                    <td>
                        <?php
                        // Calculating amount with a sign
                        $amount = $transaction['NewBalance'] - $transaction['OldBalance'];
                        $amountSign = ($amount >= 0) ? "+" : "-";
                        echo $amountSign . number_format(abs($amount), 2);
                        ?>
                    </td>
                    <td>$<?php echo number_format($transaction['OldBalance'], 2); ?></td>
                    <td>$<?php echo number_format($transaction['NewBalance'], 2); ?></td>
                    <td><?php echo htmlspecialchars($transaction['TransactionDate']); ?></td>
                    <td><?php echo htmlspecialchars($transaction['Description']); ?></td>
                </tr>
                <?php endforeach; ?>
            </table>
        </div>

        <a href="home.php" class="back-button">Back to Home</a>
    </div>

    <script>
        function confirmUpdate() {
            return confirm("Are you sure you want to change your current balance?");
        }
    </script>
</body>
</html>
