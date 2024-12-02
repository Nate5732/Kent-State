<?php
// Nathon Iadimarco
// Data Security and Privacy Final Project
// 12/1/2024
// home.php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit();
}

$user_group = $_SESSION['group_type'];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Welcome to Healthcare System</title>
</head>
<body>
    <h2>Welcome, <?php echo $_SESSION['username']; ?>!</h2>

    <h3>Choose an option:</h3>
    
    <a href="view.php">View Healthcare Data</a><br><br>

    <?php if ($user_group === 'H'): ?>
        <a href="add_data.php">Add Data</a><br><br>
    <?php endif; ?>

    <a href="login.php">Logout</a>

</body>
</html>
