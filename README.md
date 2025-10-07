# ENGG1410 Lab 1 & Lab 2 – Source Code and Executables

This document provides an explanation of the C source files and executables included in the Lab 1 and Lab 2 submissions.

---

## Lab 1 – Introduction to C Programming

### Part 1 – Printing Program (`lab1part1.c`)
- **Purpose:** Demonstrates the use of `printf()` and escape sequences in C.
- **Key Features:**
  - Prints text containing quotes, backslashes, new lines, and percentage signs.
  - Helps practice formatted output and escape characters.
- **Executable:** `lab1part1.exe`
  - Run in terminal/CLI to view the output.

---

### Part 2 – Bill Splitting Program (`lab1part2.c`)
- **Purpose:** Calculates the total bill including tip and splits it among multiple people.
- **Inputs:**
  1. Original bill amount (float).
  2. Tip percentage (integer or float).
  3. Number of people (integer).
- **Outputs:**
  - Total bill including tip (2 decimal places).
  - Each person’s share of the bill (2 decimal places).
- **Executable:** `lab1part2.exe`
  - Run the program and follow the prompts to test different scenarios.

---

### Part 3 – Debugged Weight Conversion Program (`lab1part3.c`)
- **Purpose:** Converts weight from kilograms to pounds and ounces (with fractional remainder).
- **Key Fixes Made:**
  - Corrected syntax errors (`==` replaced with `=`, missing semicolons fixed).
  - Corrected type usage (`double` for weights, `int` for truncated values).
  - Fixed incorrect `scanf()` format specifier.
- **Executable:** `lab1part3.exe`
  - Run and enter a weight in kilograms. Program outputs pounds, ounces, and fractional remainder.


---

## Included Files in ZIP Submission
- `lab1part1.c` + `lab1part1.exe`
- `lab1part2.c` + `lab1part2.exe`
- `lab1part3.c` + `lab1part3.exe`
- `Lab1and2Reportbmcrae03.pdf`
- `README.md` (this file)

---

## Notes
- If executables fail to run on another system, recompile using the provided `.c` source files.
