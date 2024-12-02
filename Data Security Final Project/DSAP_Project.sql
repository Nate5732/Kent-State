DROP DATABASE IF EXISTS `DSAP_Project`;
CREATE DATABASE `DSAP_Project`;
USE `DSAP_Project`;

CREATE TABLE Healthcare (
    id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    gender VARCHAR(10),
    age INT,
    weight INT,
    height FLOAT,
    health_history TEXT,
    data_hash VARCHAR(64)
);

DELIMITER $$

CREATE PROCEDURE PopulateHealthcare()
BEGIN
    DECLARE i INT DEFAULT 1;
    DECLARE current_first_name VARCHAR(50);
    DECLARE current_last_name VARCHAR(50);
    DECLARE current_gender VARCHAR(10);
    DECLARE current_age INT;
    DECLARE current_weight INT;
    DECLARE current_height FLOAT;
    DECLARE current_health_history TEXT;
    DECLARE current_data VARCHAR(255);
    DECLARE data_hash VARCHAR(64);

    WHILE i <= 100 DO
        SET current_first_name = CONCAT('First', i);
        SET current_last_name = CONCAT('Last', i);
        SET current_gender = CASE WHEN FLOOR(RAND() * 2) = 0 THEN 'male' ELSE 'female' END;
        SET current_age = FLOOR(18 + (RAND() * 60));
        SET current_weight = FLOOR(50 + (RAND() * 50));
        SET current_height = ROUND(150 + (RAND() * 50), 1);
        SET current_health_history = CONCAT('History record for patient ', i);
        
        SET current_data = CONCAT(
            current_first_name,
            current_last_name,
            current_gender,
            current_age,
            current_weight,
            current_height,
            current_health_history
        );

        SET data_hash = SHA2(current_data, 256);
        
        INSERT INTO Healthcare (first_name, last_name, gender, age, weight, height, health_history, data_hash)
        VALUES (
            current_first_name,
            current_last_name,
            current_gender,
            current_age,
            current_weight,
            current_height,
            current_health_history,
            data_hash
        );
        
        SET i = i + 1;
    END WHILE;
END$$

DELIMITER ;

CALL PopulateHealthcare();

SELECT 
    first_name, 
    last_name, 
    gender,
    age,
    weight, 
    height, 
    health_history
FROM Healthcare;

CREATE TABLE Users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    password_hash VARCHAR(255) NOT NULL,
    group_type ENUM('H', 'R') NOT NULL
);

INSERT INTO Users (username, password_hash, group_type) 
VALUES ('admin_username', 'hashed_password_here', 'H');

UPDATE Users
SET group_type = 'H'
WHERE username = 'admin_username';
