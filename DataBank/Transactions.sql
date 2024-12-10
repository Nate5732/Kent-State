-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Dec 04, 2024 at 09:14 PM
-- Server version: 10.3.28-MariaDB
-- PHP Version: 7.2.24

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `niadima1`
--

-- --------------------------------------------------------

--
-- Table structure for table `Transactions`
--

CREATE TABLE `Transactions` (
  `TransactionID` int(11) NOT NULL,
  `AccountID` int(11) NOT NULL,
  `TransactionType` enum('Deposit','Withdrawal') DEFAULT NULL,
  `Amount` decimal(15,2) DEFAULT NULL,
  `OldBalance` decimal(15,2) DEFAULT NULL,
  `NewBalance` decimal(15,2) DEFAULT NULL,
  `TransactionDate` timestamp NOT NULL DEFAULT current_timestamp(),
  `Description` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Transactions`
--

INSERT INTO `Transactions` (`TransactionID`, `AccountID`, `TransactionType`, `Amount`, `OldBalance`, `NewBalance`, `TransactionDate`, `Description`) VALUES
(1, 17, 'Deposit', '1.00', '8.00', '9.00', '2024-11-27 09:28:06', NULL),
(2, 17, 'Deposit', '114.00', '9.00', '123.00', '2024-11-27 09:28:28', NULL),
(3, 17, 'Withdrawal', '111.00', '123.00', '12.00', '2024-11-27 09:32:37', NULL),
(4, 17, 'Withdrawal', '765.00', '780.00', '15.00', '2024-11-27 09:37:18', NULL),
(5, 17, 'Withdrawal', '3.00', '15.00', '12.00', '2024-11-27 09:57:43', NULL),
(6, 17, 'Deposit', '6.00', '12.00', '18.00', '2024-11-27 09:59:58', NULL),
(7, 17, 'Deposit', '0.00', '18.00', '43.00', '2024-11-27 10:03:43', NULL),
(8, 17, 'Withdrawal', '0.00', '43.00', '12.00', '2024-11-27 10:04:11', NULL),
(9, 17, 'Deposit', '212333.00', '12.00', '212345.00', '2024-11-27 10:05:29', NULL),
(10, 17, 'Withdrawal', '-212302.00', '212345.00', '43.00', '2024-11-27 10:12:14', NULL),
(11, 17, 'Deposit', '2.00', '43.00', '45.00', '2024-11-27 10:13:29', NULL),
(12, 17, 'Withdrawal', '-42.00', '45.00', '3.00', '2024-11-27 10:13:48', NULL),
(13, 17, 'Deposit', '87.00', '3.00', '90.00', '2024-11-27 10:13:57', NULL),
(14, 17, 'Deposit', '10.00', '90.00', '100.00', '2024-11-27 11:02:18', NULL),
(15, 17, 'Withdrawal', '0.00', '50.00', '50.00', '2024-11-27 11:07:44', 'Manual balance change.'),
(16, 17, 'Deposit', '92.00', '50.00', '142.00', '2024-11-27 11:11:16', 'Manual balance change.'),
(17, 17, 'Withdrawal', '5.00', '137.00', '132.00', '2024-11-27 11:28:32', 'Manual balance withdrawal.'),
(18, 17, 'Withdrawal', '2.00', '130.00', '128.00', '2024-11-27 11:28:52', 'Manual balance withdrawal.'),
(19, 17, 'Withdrawal', '8.00', '120.00', '112.00', '2024-11-27 11:29:06', 'Manual balance withdrawal.'),
(20, 17, 'Withdrawal', '2.00', '110.00', '2.00', '2024-11-27 11:32:24', 'Manual balance withdrawal.'),
(21, 17, 'Withdrawal', '2.00', '0.00', '0.00', '2024-11-27 11:33:01', 'Manual balance withdrawal.'),
(22, 17, 'Deposit', '500.00', '0.00', '500.00', '2024-11-27 11:33:08', 'Manual balance change.'),
(23, 17, 'Withdrawal', '50.00', '450.00', '450.00', '2024-11-27 11:33:16', 'Manual balance withdrawal.'),
(24, 17, 'Withdrawal', '23.00', '427.00', '427.00', '2024-11-27 11:34:24', 'Manual balance withdrawal.'),
(25, 17, 'Withdrawal', '3.00', '427.00', '424.00', '2024-11-27 11:38:37', 'Manual balance withdrawal.'),
(26, 17, 'Deposit', '4.00', '424.00', '428.00', '2024-11-27 12:13:02', 'Manual balance deposit.'),
(27, 20, 'Deposit', '500.00', '0.00', '500.00', '2024-11-27 12:14:41', 'Manual balance change.'),
(28, 20, 'Withdrawal', '40.00', '500.00', '460.00', '2024-11-27 12:14:51', 'Manual balance withdrawal.'),
(29, 20, 'Deposit', '123.00', '460.00', '583.00', '2024-11-27 12:14:57', 'Manual balance deposit.'),
(30, 17, 'Deposit', '72.00', '428.00', '500.00', '2024-11-28 23:04:42', 'Manual balance change.'),
(31, 17, 'Deposit', '100.00', '500.00', '600.00', '2024-11-28 23:05:44', 'Manual balance deposit.'),
(32, 17, 'Withdrawal', '123.00', '600.00', '477.00', '2024-11-28 23:06:01', 'Manual balance withdrawal.'),
(33, 17, 'Withdrawal', '3.00', '477.00', '474.00', '2024-12-05 00:46:12', 'Manual balance withdrawal.'),
(34, 17, 'Deposit', '79.00', '474.00', '553.00', '2024-12-05 00:46:18', 'Manual balance deposit.'),
(35, 17, 'Deposit', '10.00', '553.00', '563.00', '2024-12-05 01:54:15', 'Manual balance deposit.'),
(36, 17, 'Withdrawal', '10.00', '563.00', '553.00', '2024-12-05 01:55:53', 'Manual balance withdrawal.'),
(37, 17, 'Deposit', '10.00', '553.00', '563.00', '2024-12-05 01:56:34', 'Manual balance deposit.');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Transactions`
--
ALTER TABLE `Transactions`
  ADD PRIMARY KEY (`TransactionID`),
  ADD KEY `AccountID` (`AccountID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `Transactions`
--
ALTER TABLE `Transactions`
  MODIFY `TransactionID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Transactions`
--
ALTER TABLE `Transactions`
  ADD CONSTRAINT `Transactions_ibfk_1` FOREIGN KEY (`AccountID`) REFERENCES `Accounts` (`AccountID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
