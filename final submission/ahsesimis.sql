-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:4306
-- Generation Time: Dec 05, 2025 at 06:25 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.1.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ahsesimis`
--

-- --------------------------------------------------------

--
-- Table structure for table `courses`
--

CREATE TABLE `courses` (
  `ID` int(11) NOT NULL,
  `Programme` int(11) DEFAULT NULL,
  `Level` int(11) DEFAULT NULL,
  `Semester` varchar(100) DEFAULT NULL,
  `CourseCode` varchar(50) DEFAULT NULL,
  `CourseTitle` varchar(300) DEFAULT NULL,
  `CourseCredit` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `courses`
--

INSERT INTO `courses` (`ID`, `Programme`, `Level`, `Semester`, `CourseCode`, `CourseTitle`, `CourseCredit`) VALUES
(1, 1, 300, 'First Semester', 'CS 256', 'STEM', 2),
(2, 2, 600, 'Second Semester', 'CS4443', 'Gamification', 2);

-- --------------------------------------------------------

--
-- Table structure for table `course_assignments`
--

CREATE TABLE `course_assignments` (
  `ID` int(11) NOT NULL,
  `FacultyID` int(11) DEFAULT NULL,
  `CourseID` int(11) DEFAULT NULL,
  `Semester` varchar(50) DEFAULT NULL,
  `AcademicYear` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `department`
--

CREATE TABLE `department` (
  `ID` int(11) NOT NULL,
  `Department` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`ID`, `Department`) VALUES
(1, 'CS and MIS'),
(3, 'BA'),
(4, 'ECONOMICS'),
(5, 'Computer Science and MIS'),
(6, 'Business Administration'),
(7, 'Economics'),
(8, 'Engineering');

-- --------------------------------------------------------

--
-- Table structure for table `faculty`
--

CREATE TABLE `faculty` (
  `ID` int(11) NOT NULL,
  `UserID` int(11) DEFAULT NULL,
  `DepartmentID` int(11) DEFAULT NULL,
  `FacultyID` varchar(50) DEFAULT NULL,
  `Position` varchar(100) DEFAULT NULL,
  `status` enum('active','inactive','','') NOT NULL DEFAULT 'active',
  `hire_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `faculty`
--

INSERT INTO `faculty` (`ID`, `UserID`, `DepartmentID`, `FacultyID`, `Position`, `status`, `hire_date`) VALUES
(1, 5, 1, '99392027', 'Lecturer', 'active', '2025-02-23'),
(2, 3, 1, '98982023', 'Lecturer', 'active', '2025-01-03'),
(3, 4, 4, '20001999', 'Assistant Professor', 'active', '2025-12-05');

-- --------------------------------------------------------

--
-- Table structure for table `grades`
--

CREATE TABLE `grades` (
  `ID` int(11) NOT NULL,
  `StudentID` int(11) DEFAULT NULL,
  `CourseID` int(11) DEFAULT NULL,
  `FacultyID` int(11) DEFAULT NULL,
  `Grade` varchar(2) DEFAULT NULL,
  `GradePoints` decimal(3,2) DEFAULT NULL,
  `Semester` varchar(50) DEFAULT NULL,
  `AcademicYear` varchar(20) DEFAULT NULL,
  `DateEntered` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `grades`
--

INSERT INTO `grades` (`ID`, `StudentID`, `CourseID`, `FacultyID`, `Grade`, `GradePoints`, `Semester`, `AcademicYear`, `DateEntered`) VALUES
(1, 1, 2, NULL, 'A+', 4.00, 'First Semester', '2025', '2025-12-05 16:46:15'),
(2, 3, 2, NULL, 'A', 4.00, 'First Semester', '2024-2025', '2025-12-05 16:47:15');

-- --------------------------------------------------------

--
-- Table structure for table `prerequisites`
--

CREATE TABLE `prerequisites` (
  `ID` int(11) NOT NULL,
  `CourseID` int(11) DEFAULT NULL,
  `PrerequisiteCourseID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `programmes`
--

CREATE TABLE `programmes` (
  `ID` int(11) NOT NULL,
  `Department` int(11) DEFAULT NULL,
  `Programme` varchar(200) DEFAULT NULL,
  `Programmetype` enum('BSc','BA','MSc','MA','PhD') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `programmes`
--

INSERT INTO `programmes` (`ID`, `Department`, `Programme`, `Programmetype`) VALUES
(1, 1, 'STEM', 'BSc'),
(2, 1, 'Gaming', 'MSc');

-- --------------------------------------------------------

--
-- Table structure for table `roles`
--

CREATE TABLE `roles` (
  `ID` int(11) NOT NULL,
  `RoleName` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `roles`
--

INSERT INTO `roles` (`ID`, `RoleName`) VALUES
(1, 'Administrator'),
(2, 'Faculty'),
(3, 'Student');

-- --------------------------------------------------------

--
-- Table structure for table `students`
--

CREATE TABLE `students` (
  `ID` int(11) NOT NULL,
  `UserID` int(11) DEFAULT NULL,
  `StudentID` varchar(50) DEFAULT NULL,
  `ProgrammeID` int(11) DEFAULT NULL,
  `Level` int(11) DEFAULT NULL,
  `status` enum('active','inactive','','') NOT NULL DEFAULT 'active',
  `date_of_enrollment` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `students`
--

INSERT INTO `students` (`ID`, `UserID`, `StudentID`, `ProgrammeID`, `Level`, `status`, `date_of_enrollment`) VALUES
(1, 1, '99492029', 2, 300, 'active', '2025-02-23'),
(2, 3, '99992027', 1, 200, 'active', '2023-05-21'),
(3, 7, '99992002', 2, 300, 'active', '2023-09-16');

-- --------------------------------------------------------

--
-- Table structure for table `student_courses`
--

CREATE TABLE `student_courses` (
  `ID` int(11) NOT NULL,
  `StudentID` int(11) DEFAULT NULL,
  `CourseID` int(11) DEFAULT NULL,
  `Semester` varchar(50) DEFAULT NULL,
  `AcademicYear` varchar(20) DEFAULT NULL,
  `RegistrationDate` timestamp NOT NULL DEFAULT current_timestamp(),
  `Status` enum('Registered','Dropped','Completed') DEFAULT 'Registered'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `ID` int(11) NOT NULL,
  `FirstName` varchar(150) NOT NULL,
  `LastName` varchar(150) NOT NULL,
  `Email` varchar(150) NOT NULL,
  `Password` varchar(150) NOT NULL,
  `role` int(11) DEFAULT 3
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`ID`, `FirstName`, `LastName`, `Email`, `Password`, `role`) VALUES
(1, 'Ben', 'Changdar', 'benriak1@gmail.com', 'nyewar9939', 3),
(3, 'Sam', 'Blankson', 'icp@gmail.com', 'icp2025', 2),
(4, 'Koy', 'Changdar', 'koychangdar@gmail.com', 'koy9939', 2),
(5, 'Joseph', 'Mensah', 'jomens@gmail.com', 'jomens123', 2),
(6, 'Phenomenal', 'Changdar', 'changdar@gmail.com', 'changdar123', 1),
(7, 'Kuanen', 'Changdar', 'kuanen@gmail.com', 'kuanen123', 3);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `courses`
--
ALTER TABLE `courses`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Programme` (`Programme`);

--
-- Indexes for table `course_assignments`
--
ALTER TABLE `course_assignments`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `FacultyID` (`FacultyID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `department`
--
ALTER TABLE `department`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `faculty`
--
ALTER TABLE `faculty`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `UserID` (`UserID`),
  ADD KEY `DepartmentID` (`DepartmentID`);

--
-- Indexes for table `grades`
--
ALTER TABLE `grades`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `CourseID` (`CourseID`),
  ADD KEY `FacultyID` (`FacultyID`);

--
-- Indexes for table `prerequisites`
--
ALTER TABLE `prerequisites`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `CourseID` (`CourseID`),
  ADD KEY `PrerequisiteCourseID` (`PrerequisiteCourseID`);

--
-- Indexes for table `programmes`
--
ALTER TABLE `programmes`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `Department` (`Department`);

--
-- Indexes for table `roles`
--
ALTER TABLE `roles`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `students`
--
ALTER TABLE `students`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `UserID` (`UserID`),
  ADD KEY `ProgrammeID` (`ProgrammeID`);

--
-- Indexes for table `student_courses`
--
ALTER TABLE `student_courses`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `CourseID` (`CourseID`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `Email` (`Email`),
  ADD KEY `role` (`role`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `courses`
--
ALTER TABLE `courses`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `course_assignments`
--
ALTER TABLE `course_assignments`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `department`
--
ALTER TABLE `department`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `faculty`
--
ALTER TABLE `faculty`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `grades`
--
ALTER TABLE `grades`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `prerequisites`
--
ALTER TABLE `prerequisites`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `programmes`
--
ALTER TABLE `programmes`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `roles`
--
ALTER TABLE `roles`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `students`
--
ALTER TABLE `students`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `student_courses`
--
ALTER TABLE `student_courses`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `courses`
--
ALTER TABLE `courses`
  ADD CONSTRAINT `courses_ibfk_1` FOREIGN KEY (`Programme`) REFERENCES `programmes` (`ID`);

--
-- Constraints for table `course_assignments`
--
ALTER TABLE `course_assignments`
  ADD CONSTRAINT `course_assignments_ibfk_1` FOREIGN KEY (`FacultyID`) REFERENCES `faculty` (`ID`),
  ADD CONSTRAINT `course_assignments_ibfk_2` FOREIGN KEY (`CourseID`) REFERENCES `courses` (`ID`);

--
-- Constraints for table `faculty`
--
ALTER TABLE `faculty`
  ADD CONSTRAINT `faculty_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `users` (`ID`),
  ADD CONSTRAINT `faculty_ibfk_2` FOREIGN KEY (`DepartmentID`) REFERENCES `department` (`ID`);

--
-- Constraints for table `grades`
--
ALTER TABLE `grades`
  ADD CONSTRAINT `grades_ibfk_1` FOREIGN KEY (`StudentID`) REFERENCES `students` (`ID`),
  ADD CONSTRAINT `grades_ibfk_2` FOREIGN KEY (`CourseID`) REFERENCES `courses` (`ID`),
  ADD CONSTRAINT `grades_ibfk_3` FOREIGN KEY (`FacultyID`) REFERENCES `faculty` (`ID`);

--
-- Constraints for table `prerequisites`
--
ALTER TABLE `prerequisites`
  ADD CONSTRAINT `prerequisites_ibfk_1` FOREIGN KEY (`CourseID`) REFERENCES `courses` (`ID`),
  ADD CONSTRAINT `prerequisites_ibfk_2` FOREIGN KEY (`PrerequisiteCourseID`) REFERENCES `courses` (`ID`);

--
-- Constraints for table `programmes`
--
ALTER TABLE `programmes`
  ADD CONSTRAINT `programmes_ibfk_1` FOREIGN KEY (`Department`) REFERENCES `department` (`ID`);

--
-- Constraints for table `students`
--
ALTER TABLE `students`
  ADD CONSTRAINT `students_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `users` (`ID`),
  ADD CONSTRAINT `students_ibfk_2` FOREIGN KEY (`ProgrammeID`) REFERENCES `programmes` (`ID`);

--
-- Constraints for table `student_courses`
--
ALTER TABLE `student_courses`
  ADD CONSTRAINT `student_courses_ibfk_1` FOREIGN KEY (`StudentID`) REFERENCES `students` (`ID`),
  ADD CONSTRAINT `student_courses_ibfk_2` FOREIGN KEY (`CourseID`) REFERENCES `courses` (`ID`);

--
-- Constraints for table `users`
--
ALTER TABLE `users`
  ADD CONSTRAINT `users_ibfk_1` FOREIGN KEY (`role`) REFERENCES `roles` (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
