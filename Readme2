# Student Result Management System (C++)

**Course:** Object-Oriented Programming using C++ Lab
**Task:** Task 2
**Institution:** Nitte Meenakshi Institute of Technology (NMIT), Dept. of Electronics and Communication Engineering

A C++ program that manages student records using a base class `Student` and a derived class `Result`. It validates marks with exception handling, shows results through runtime polymorphism, saves and reloads records from a text file, and filters students above a cutoff using an STL algorithm with a lambda expression.

---

## Features

- Stores student records dynamically in a `std::vector<Result>`
- Validates marks (must be 0–100); an invalid record throws an exception and is not stored
- Displays every record through a base-class pointer (runtime polymorphism)
- Shows PASS (marks of 40 or above) or FAIL for each student
- Saves records to `results.txt` and reads them back
- Lists students scoring above a cutoff (80) using `for_each` and a lambda

## C++ Concepts Demonstrated

| Concept | Where it is used |
|---------|------------------|
| Classes and objects | `Student` and `Result` classes; each record is an object |
| Inheritance | `Result` publicly inherits from `Student`, reusing `rollNo` and `name` |
| Runtime polymorphism | Virtual `display()` in `Student`, overridden in `Result`, called through a `Student*` |
| Virtual destructor | `virtual ~Student()` for safe destruction through base pointers |
| Exception handling | `Result` constructor throws `invalid_argument` for marks outside 0–100; caught in `main()` |
| File handling | `ofstream` writes and `ifstream` reads `results.txt` |
| STL vector | `vector<Result>` with `emplace_back()` |
| STL algorithms and lambdas | `for_each` with a lambda that captures the cutoff value |
| Operator overloading | Friend `operator<<` writes a `Result` directly to an `ofstream` |

## Class Overview

```
Student (base)                    Result (derived)
├─ protected: rollNo, name        ├─ public: float marks
├─ virtual display() const        ├─ constructor validates marks (0-100)
└─ virtual ~Student()             ├─ display() override (PASS if marks >= 40)
                                  └─ friend operator<<(ofstream&, const Result&)
```

## How the Program Works

1. Adds four records inside a `try` block. The fourth has marks of 150, so the constructor throws an exception. It is caught and reported, and the first three valid records stay in the vector.
2. Displays all records through a `Student*` pointer, which calls the overridden `display()`.
3. Saves the records to `results.txt` using the overloaded `<<` operator, reads them back with `ifstream` and displays them again.
4. Uses `for_each` with a lambda to display only students scoring above the cutoff of 80.

## Getting Started

### Requirements

- A C++ compiler with C++11 or later support (developed with `g++` in Visual Studio Code)

### Compile

```bash
g++ -o student_class student_class.cpp
```

### Run

```bash
./student_class
```

On Windows, run `student_class.exe` instead. The program creates `results.txt` in the folder you run it from.

## Sample Output

```
Exception Caught: Marks must be 0-100

--- All Student Results ---
Roll: 101 | Name: Alice | Marks: 85.5 | PASS
Roll: 102 | Name: Bob | Marks: 35 | FAIL
Roll: 103 | Name: Charlie | Marks: 92 | PASS

--- Retrieved from File ---
Roll: 101 | Name: Alice | Marks: 85.5 | PASS
Roll: 102 | Name: Bob | Marks: 35 | FAIL
Roll: 103 | Name: Charlie | Marks: 92 | PASS

--- Students Scoring Above 80 ---
Roll: 101 | Name: Alice | Marks: 85.5 | PASS
Roll: 103 | Name: Charlie | Marks: 92 | PASS
```

### Data File Format

Each line of `results.txt` is one record:

```
RollNo Name Marks
```

Example:

```
101 Alice 85.5
```

## Repository Structure

```
.
├── student_class.cpp   # Source code
├── results.txt         # Generated when the program runs
├── screenshots/        # Output screenshots
├── Report.pdf          # Task 2 lab report
└── README.md
```

## Author

- **Name:** Arush Singh
- **USN:** NB25ECE027
- **Section:** SEC A
- **GitHub:** [ArushSingh11](https://github.com/ArushSingh11)

## Declaration

This project was completed as part of the OOP using C++ Lab coursework and represents my own work.
