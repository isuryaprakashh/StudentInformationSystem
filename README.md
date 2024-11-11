# Student Information System

## Overview
The **Student Information System** is a program designed to manage student records using a linked list data structure. It allows users to perform various operations such as inserting, searching, updating, and deleting student records.

The program dynamically allocates and deallocates memory for storing student information, which includes the first name, last name, course code, and grade. The system provides a user-friendly interface for interacting with the student records and also saves the data to a file named `student_data.txt` for future reference.

The program is implemented in the C programming language and follows a modular approach, with separate functions for each operation. The linked list data structure ensures efficient memory management and allows for dynamic resizing as the number of student records grows or shrinks. The program also includes error handling mechanisms to ensure robustness and reliability.

## Features
- **Add Student Data:** Enter student details, including first name, last name, course, and grade.
- **Display and Save Student Data:** Display all student records and save them to a file named `student_data.txt`.
- **Delete Student Data:** Remove a student record by searching for the student's first name.
- **Update Student Data:** Update student details, including the first name, last name, course, and grade.
- **Search by First Name:** Search and display student records by first name.

## Functions

### `create()`
This function allows users to add a new student record to the linked list. It asks for the student's first name, last name, course code, and grade.

### `display()`
This function displays all student records in a tabular format and appends them to a file named `student_data.txt` for future reference.

### `deleted()`
This function allows the user to delete a student record by searching for the student's first name. If the record is found, it will be removed from the linked list and freed from memory.

### `update()`
This function allows the user to update an existing student record by searching for the student's first name. The user can update the first name, last name, course, and grade.

### `searchfname()`
This function allows the user to search for student records by the first name. All matching student records are displayed.

## Compilation and Execution

To compile the program, use the following command:

```bash
gcc -o student_info student_info.c

```

#EXAMPLE USAGE

**STUDENT INFORMATION SYSTEM**

Enter :
1.To ADD     Student Details
2.To DISPLAY and SAVE Student Details
3.To DELETE  Student Details
4.To UPDATE  Student Details 
5.To SEARCH  Student Details 
6.To EXIT 

Enter Your Choice : 1
Enter Student's first Name: John
Enter Students's second Name: Doe
Enter Course Code: CS101
Enter the Students Grade: 85.5
Student Data Entered Successfully

Enter :
1.To ADD     Student Details
2.To DISPLAY and SAVE Student Details
3.To DELETE  Student Details
4.To UPDATE  Student Details 
5.To SEARCH  Student Details 
6.To EXIT 

Enter Your Choice : 2
FIRST_NAME	LAST_NAME	COURSE		GRADE
John		Doe		CS101		85.50
Data saved to student data.txt file.



