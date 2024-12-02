<?php
// Nathon Iadimarco
// Data Security and Privacy Final Project
// 12/1/2024
// login.php
session_start();
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "DSAP_Project";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $input_username = $_POST['username'];
    $input_password = $_POST['password'];

    $stmt = $conn->prepare("SELECT username, password_hash, group_type FROM Users WHERE username = ?");
    $stmt->bind_param("s", $input_username);
    $stmt->execute();
    $result = $stmt->get_result();
    $user = $result->fetch_assoc();

    if ($user && password_verify($input_password, $user['password_hash'])) {
        $_SESSION['username'] = $user['username'];
        $_SESSION['group_type'] = $user['group_type'];

        header("Location: home.php");
        exit();
    } else {
        echo "Invalid username or password.";
    }
}
?>

<!-- HTML for login page -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
</head>
<body>
    <h2>Login</h2>
    <form method="POST" action="login.php">
        <label for="username">Username:</label>
        <input type="text" name="username" required><br><br>

        <label for="password">Password:</label>
        <input type="password" name="password" required><br><br>

        <button type="submit">Login</button>
    </form>

    <div>
        <p>Don't have an account? <a href="Project.html">Register now!</a>.</p>
    </div>
</body>
</html>
