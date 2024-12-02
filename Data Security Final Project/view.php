<?php
// Nathon Iadimarco
// Data Security and Privacy Final Project
// 12/1/2024
// view.php
session_start();

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "DSAP_Project";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$group_type = $_SESSION['group_type']; // Storing users group "H or R"

$searchFirst = "";
$searchLast = "";
$searchGender = "";
$searchAge = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['search'])) {
        $searchFirst = $_POST['first_name'];
        $searchLast = $_POST['last_name'];
        $searchGender = $_POST['gender'];
        $searchAge = $_POST['age'];
    } elseif (isset($_POST['show_all'])) {
        $searchFirst = "";
        $searchLast = "";
        $searchGender = "";
        $searchAge = "";
    }
}

// Creating the query based on search filters, also completing data integrity presentation
$query = "SELECT 
             id,
             first_name, 
             last_name, 
             gender,
             age,
             weight, 
             height, 
             health_history,
             data_hash,
             CASE
                 WHEN data_hash = SHA2(CONCAT(first_name, last_name, gender, age, weight, height, health_history), 256) THEN 'Safe'
                 ELSE 'Tampered!!' 
             END AS data_integrity
           FROM Healthcare";

$conditions = [];
// Search conditions
if ($searchFirst != "") {
    $conditions[] = "first_name LIKE '%" . $conn->real_escape_string($searchFirst) . "%'";
}

if ($searchLast != "") {
    $conditions[] = "last_name LIKE '%" . $conn->real_escape_string($searchLast) . "%'";
}

if ($searchGender != "") {
    $conditions[] = "gender = '" . $conn->real_escape_string($searchGender) . "'";
}

if ($searchAge != "") {
    $conditions[] = "age = " . (int)$searchAge;
}

if (count($conditions) > 0) { // Allowing search and filter for inputted query
    $query .= " WHERE " . implode(" AND ", $conditions);
}

$result = $conn->query($query);

// Checking if results have changed since the last session
$query_data = "";
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $query_data .= implode("", array_map('trim', $row));
    }
    $result->data_seek(0);
}

// Generating a hash for the current query results
$current_query_hash = hash('sha256', $query_data);

// Comparing it with the hash stored in the session
$query_changed = false;
if (isset($_SESSION['previous_query_hash']) && $_SESSION['previous_query_hash'] !== $current_query_hash) {
    $query_changed = true;
}

// Storing the current query hash in the session
$_SESSION['previous_query_hash'] = $current_query_hash;
?>

<!-- HTML Section -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Healthcare Data</title>
</head>
<body>

<h1>Welcome, <?php echo $_SESSION['username']; ?>!</h1>

<?php if ($query_changed): ?>
    <p style="color: red;">The query results have changed since your last session.</p>
<?php elseif (isset($_SESSION['previous_query_hash'])): ?>
    <p style="color: green;">The query results are consistent with your last session.</p>
<?php endif; ?>

<!-- Search HTML Section -->
<form method="POST" action="view.php">
    <label for="first_name">First Name:</label>
    <input type="text" name="first_name" value="<?php echo htmlspecialchars($searchFirst); ?>">
    
    <label for="last_name">Last Name:</label>
    <input type="text" name="last_name" value="<?php echo htmlspecialchars($searchLast); ?>">

    <label for="gender">Gender:</label>
    <input type="text" name="gender" value="<?php echo htmlspecialchars($searchGender); ?>">

    <label for="age">Age:</label>
    <input type="text" name="age" value="<?php echo htmlspecialchars($searchAge); ?>">

    <button type="submit" name="search">Search</button>
    <button type="submit" name="show_all">Show All</button>
</form>

<!-- Healthcare Data Table -->
<table border="1">
    <thead>
        <tr>
            <th>User ID</th>
            <?php if ($group_type == 'R') { echo "<th>First Name (Blocked)</th><th>Last Name (Blocked)</th>"; } else { echo "<th>First Name</th><th>Last Name</th>"; } ?>
            <th>Gender</th>
            <th>Age</th>
            <th>Weight</th>
            <th>Height</th>
            <th>Health History</th>
            <th>Data Integrity</th>
        </tr>
    </thead>
    <tbody>
        
        <?php 
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
        ?>
            <tr>
                <td><?php echo htmlspecialchars($row['id']); ?></td>
                <?php if ($group_type == 'R') { ?>
                    <td>*****</td> <!-- Blocking first name for group R -->
                    <td>*****</td> <!-- Blocking last name for group R -->
                <?php } else { ?>
                    <td><?php echo htmlspecialchars($row['first_name']); ?></td>
                    <td><?php echo htmlspecialchars($row['last_name']); ?></td>
                <?php } ?>
                <td><?php echo htmlspecialchars($row['gender']); ?></td>
                <td><?php echo htmlspecialchars($row['age']); ?></td>
                <td><?php echo htmlspecialchars($row['weight']); ?></td>
                <td><?php echo htmlspecialchars($row['height']); ?></td>
                <td><?php echo htmlspecialchars($row['health_history']); ?></td>
                <td><?php echo htmlspecialchars($row['data_integrity']); ?></td>
            </tr>
        <?php 
            } 
        } else {
            echo "<tr><td colspan='8'>No results found.</td></tr>";
        }
        ?>
    </tbody>
</table>

<a href="home.php">Home</a>
<?php if ($group_type === 'H'): ?>
    <a href="add_data.php">Add Data</a><br><br>
<?php endif; ?>
<a href="login.php">Logout</a>

</body>
</html>
