<?php
// Nathon Iadimarco
// Data Security and Privacy Final Project
// 12/1/2024
// add_data.php
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
    $first_name = trim($_POST['first_name']);
    $last_name = trim($_POST['last_name']);
    $gender = trim($_POST['gender']);
    $age = (int)$_POST['age'];
    $weight = (float)$_POST['weight'];
    $height = (float)$_POST['height'];
    $health_history = trim($_POST['health_history']);

    if (empty($first_name) || empty($last_name) || empty($gender) || empty($age) || empty($weight) || empty($height) || empty($health_history)) {
        die("All fields are required.");
    }

    $current_data = $first_name . $last_name . $gender . $age . $weight . $height . $health_history;

    // Generating the hash using SHA256
    $data_hash = hash('sha256', $current_data);

    // Inserting data and hash into table
    $stmt = $conn->prepare("INSERT INTO Healthcare (first_name, last_name, gender, age, weight, height, health_history, data_hash) 
                            VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    if (!$stmt) {
        die("Statement preparation failed: " . $conn->error);
    }

    $stmt->bind_param("sssiddss", 
        $first_name, 
        $last_name, 
        $gender, 
        $age, 
        $weight, 
        $height, 
        $health_history, 
        $data_hash
    );

    if ($stmt->execute()) { // Giving feedback to the user
        echo "Data added successfully!";
    } else {
        echo "Error: " . $stmt->error;
    }

    $stmt->close();
}

?>

<!-- HTML for add data page -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add Data</title>
</head>
<body>
    <h2>Add Healthcare Data</h2>
    <form method="POST" action="add_data.php">
        <label for="first_name">First Name:</label>
        <input type="text" name="first_name" required><br>

        <label for="last_name">Last Name:</label>
        <input type="text" name="last_name" required><br>

        <label for="gender">Gender (Male, Female):</label>
        <select name="gender" required>
            <option value="">Select</option>
            <option value="Male">Male</option>
            <option value="Female">Female</option>
        </select><br>

        <label for="age">Age:</label>
        <input type="number" name="age" required><br>

        <label for="weight">Weight (kg):</label>
        <input type="number" step="0.1" name="weight" required><br>

        <label for="height">Height (cm):</label>
        <input type="number" step="0.1" name="height" required><br>

        <label for="health_history">Health History:</label>
        <textarea name="health_history" required></textarea><br>

        <button type="submit">Add Data</button>
    </form>
    <a href="view.php">View Healthcare Data</a><br><br>
    <a href="logout.php">Logout</a>
</body>
</html>
