<?php
// Nathon Iadimarco
// 11/27/2024
// Introduction to Database System Design
// Final Project Application Implementation
// DataBank.php

session_start();
include('config.php');
$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$errorMessage = '';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = trim($_POST['username']);
    $password = trim($_POST['password']);

    $sql = "SELECT * FROM Accounts WHERE Username = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("s", $username);
    $stmt->execute();
    $result = $stmt->get_result();

    // Check if user exists
    if ($result && $result->num_rows > 0) {
        $user = $result->fetch_assoc();

        // Verify password
        if (password_verify($password, $user['PasswordHash'])) {
            $_SESSION['AccountID'] = $user['AccountID'];
            $_SESSION['Username'] = $user['Username'];
            $_SESSION['Role'] = $user['Role'];
            $_SESSION['FirstName'] = $user['FirstName'];

            // Redirect to home.php
            header('Location: home.php');
            exit();
        } else {
            $errorMessage = 'Invalid password.';
        }
    } else {
        $errorMessage = 'No account found with that username.';
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DataBank - Login</title>
    <link rel="stylesheet" href="log_reg.css">
</head>
<body>
    <div class="container">
        <h1 class="title">DataBank - Login</h1>
        <p class="description">Visualizing and managing your financial transactions has never been easier.</p>

        <?php if ($errorMessage): ?>
            <div class="error"><?php echo $errorMessage; ?></div>
        <?php endif; ?>

        <div class="login-container">
            <form action="DataBank.php" method="POST">
                <input type="text" name="username" placeholder="Username" required>
                <input type="password" name="password" placeholder="Password" required>
                <input type="submit" value="Login">
            </form>
        </div>
        <p class="register-text">Don’t have an account? <a href="register.php">Register here</a></p>
    </div>
</body>
</html>
