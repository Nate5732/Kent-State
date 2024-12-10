<?php
// Nathon Iadimarco
// 11/27/2024
// Introduction to Database System Design
// Final Project Application Implementation
// config.php

/* Database credentials. */
$servername = 'localhost';
$username = 'niadima1'; // Flashline username
$password = 'rmcRV12t'; // phpMyAdmin password
$dbname = 'niadima1'; // Flashline username

/* Attempt to connect to MySQL database */
$mysqli = new mysqli($servername, $username, $password, $dbname);

// Check connection
if($mysqli === false){
    die("ERROR: Could not connect. " . $mysqli->connect_error);
}
?>
