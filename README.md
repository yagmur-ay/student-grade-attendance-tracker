# Student Grade & Attendance Tracker

A console-based C++ application for managing student grades and attendance, built as a practice project to apply core C++ concepts: arrays, functions, references, string handling, and sorting algorithms.

## Features

- **Add Student** — register a new student (name + absence count)
- **Enter Grades** — input three exam grades for a selected student
- **Calculate Average** — compute and display the average grade for every student
- **Find Min/Max Average** — identify the students with the highest and lowest average grades
- **Search by Name** — look up a student by name
- **List Absent Students** — list students whose absences exceed a given limit
- **Sort Students** — sort all students alphabetically by name (while keeping their grades and absence data correctly linked)
- **List Students** — display all registered students

## Built With

- **C++**
  - Parallel arrays for storing related student data (names, grades, absences)
  - Functions with array parameters and reference parameters (`&`)
  - `switch` / `do-while` menu-driven program flow
  - String comparison and handling (`std::string`)
  - Bubble sort algorithm (sorting multiple linked arrays together)

## How to Run

Compile with g++ (or any C++ compiler):

```bash
g++ student_grade_attendance_tracker.cpp -o student_grade_attendance_tracker
./student_grade_attendance_tracker
```

On Windows (PowerShell):

```powershell
g++ student_grade_attendance_tracker.cpp -o student_grade_attendance_tracker
.\student_grade_attendance_tracker
```

## Menu Overview

```
1. Add Student
2. Enter Grades
3. Calculate Average
4. Find Min/Max Average
5. Search by Name
6. List Absent Students
7. List Students
8. Sort Students
9. Exit
```

## Known Limitations

- Maximum capacity is 20 students (fixed-size arrays)
- Grade and absence inputs are not validated for realistic ranges (e.g., negative numbers or grades above 100 are accepted)
- Non-numeric input where a number is expected (e.g., typing letters for a grade) is not handled and may cause unexpected behavior

## What I Learned

- Managing multiple parallel arrays and keeping their indices synchronized
- Passing arrays and references to functions in C++
- The difference between pass-by-value and pass-by-reference, and when each is needed
- Implementing bubble sort across several linked arrays at once
- Basic defensive programming: guarding against invalid indices and empty data sets

## Author

Yagmur Ay