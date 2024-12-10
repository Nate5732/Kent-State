<?php
// Nathon Iadimarco
// 11/27/2024
// Introduction to Database System Design
// Final Project Application Implementation
// home.php

session_start();
include('config.php');
$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$FirstName = $_SESSION['FirstName'];
$accountID = $_SESSION['AccountID'];
$balance = $_SESSION['Balance'];

// Fetch the current balance from the database
$sql = "SELECT Balance FROM Accounts WHERE AccountID = '$accountID'";
$result = mysqli_query($conn, $sql);
$row = mysqli_fetch_assoc($result);

$balance = $row['Balance'] ?? 0.00;
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DataBank - Home</title>
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
        <h1 class="title">Welcome, <?php echo htmlspecialchars($FirstName); ?>!</h1>
        <label for="balance" class="description">Your current balance is:</label>
    </div>

    <!-- Form for updating balance -->
    <form action="transactions.php" method="POST" onsubmit="return confirmUpdate();">
        <span class="currency"> $ </span>
        <input type="number" name="balance" id="balance" step=".01" value="<?php echo htmlspecialchars($balance); ?>" class="balance-input">
    <input type="hidden" name="description" value="Manual balance change.">
        <button type="submit" class="change-button">Change Balance</button>
    </form>

    <script>
        function confirmUpdate() {
            return confirm("Are you sure you want to change your current balance?");
        }
    </script>

    <!-- Button Container -->
    <div class="button-container">
        <a href="withdraw.php" class="large-button">Withdraw Funds</a>
        <a href="deposit.php" class="large-button">Deposit Funds</a>
        <a href="transactions.php" class="large-button">Transaction History</a>
    </div>
</body>
</html>
