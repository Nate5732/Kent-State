<?php
// Nathon Iadimarco
// 11/27/2024
// Introduction to Database System Design
// Final Project Application Implementation
// update_balance.php
session_start();
include('config.php');

if (!isset($_SESSION['AccountID'])) {
    header('Location: home.php');
    exit();
}

$accountID = $_SESSION['AccountID'];

// Check if the form is submitted and the balance is provided
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['balance'])) {
    $newBalance = mysqli_real_escape_string($conn, $_POST['balance']);
    
    // Checking if updated balance is numeric and greater than/equal to 0
    if (is_numeric($newBalance) && $newBalance >= 0) {
        // Update the balance in the database
        $sql = "UPDATE Accounts SET Balance = '$newBalance' WHERE AccountID = '$accountID'";

        if (mysqli_query($conn, $sql)) {
            // Redirecting to home page with a success message
            header('Location: home.php?status=success');
        } else {
            echo "Error updating balance: " . mysqli_error($conn);
        }
    } else {
        echo "Invalid balance value!";
    }
}
?>
