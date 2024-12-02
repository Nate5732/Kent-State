<?php
// Nathon Iadimarco
// Data Security and Privacy Final Project
// 12/1/2024
// register.php
$servername = "localhost";
$username = "root";
$password = ""; 
$dbname = "DSAP_Project";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}


if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['register'])) {
    $username = isset($_POST['username']) ? trim($_POST['username']) : null;
    $password = isset($_POST['password']) ? trim($_POST['password']) : null;

    if (!$username || !$password) {
        echo "All fields are required.";
    } else {
        // Hashing the password
        $password_hash = password_hash($password, PASSWORD_BCRYPT);

        // Default group is R for all users. (Can change to an H user in the Database)
        $group_type = 'R';

        // Insert the user into the SQL Users Table.
        $stmt = $conn->prepare("INSERT INTO Users (username, password_hash, group_type) VALUES (?, ?, ?)");
        $stmt->bind_param("sss", $username, $password_hash, $group_type);
        
        if ($stmt->execute()) {
            header("Location: project.html?success=1");
            exit();
        } else {
            echo "Error: " . $stmt->error;
        }
    }
}
?>
