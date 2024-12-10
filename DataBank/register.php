<?php
// Nathon Iadimarco
// 11/27/2024
// Introduction to Database System Design
// Final Project Application Implementation
// register.php

include('config.php');

$errorMessage = '';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $FirstName = mysqli_real_escape_string($mysqli, $_POST['FirstName']);
    $LastName = mysqli_real_escape_string($mysqli, $_POST['LastName']);
    $Username = mysqli_real_escape_string($mysqli, $_POST['Username']);
    $Password = mysqli_real_escape_string($mysqli, $_POST['Password']);

    // Hash the password before saving to the database
    $PasswordHash = password_hash($Password, PASSWORD_DEFAULT);

    // Insert into Accounts table
    $sql = "INSERT INTO Accounts (FirstName, LastName, Role, Username, PasswordHash) 
            VALUES ('$FirstName', '$LastName', 'User', '$Username', '$PasswordHash')";

    // Insert data into the database
    if (mysqli_query($mysqli, $sql)) {
        header('Location: DataBank.php');
        exit();
    } else {
        $errorMessage = "An error occurred during registration. Please try again. Error: " . mysqli_error($mysqli);
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DataBank - Register</title>
    <link rel="stylesheet" href="log_reg.css"> <!-- Link to your existing CSS -->
</head>
<body>
    <div class="container">
        <h1 class="title">DataBank - Register</h1>
        <p class="description">Visualizing and managing your financial transactions has never been easier.</p>

        <?php if ($errorMessage): ?>
            <div class="error"><?php echo $errorMessage; ?></div>
        <?php endif; ?>

        <div class="login-container">
            <form action="register.php" method="POST">
                <input type="text" name="FirstName" placeholder="FirstName" required>
                <input type="text" name="LastName" placeholder="LastName" required>
                <input type="text" name="Username" placeholder="Username" required>
                <input type="password" name="Password" placeholder="Password" required>
                <input type="submit" value="Register">
            </form>
        </div>

        <p class="register-text">Already have an account? <a href="DataBank.php">Log in here</a></p>
    </div>
</body>
</html>
