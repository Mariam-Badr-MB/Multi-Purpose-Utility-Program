# MultiPurposeUtilityProgram

## Overview
This program is a multi-functional utility tool designed to solve a variety of common computational problems, including:

1. **Text Modification**: Removes extra spaces between words and adjusts sentence capitalization.
2. **Prime Number Finder**: Finds all prime numbers up to a given number.
3. **Domino Chain Solver**: Checks if it's possible to arrange domino pieces such that the right side of one piece matches the left side of the next.
4. **Text File Editor**: Modifies the content of a text file by replacing inappropriate or undesired words with polite alternatives based on a provided dictionary.

---

## Features
- **User-Friendly Menu**: Offers an interactive menu for choosing tasks.
- **Input Validation**: Ensures that user inputs are valid and handles errors gracefully.
- **Flexible File Handling**: Allows users to specify their own input files or use default ones.
- **Efficient Algorithms**: Implements optimized algorithms for prime number generation and domino chain solving.

---

## How to Use
1. **Run the program** using any C++ compiler supporting modern C++ standards (e.g., C++11 and above).
2. Follow the on-screen menu to select a task:
   - Modify a sentence.
   - Find prime numbers.
   - Solve a domino chain.
   - Edit a text file based on a word dictionary.
3. Input the required data when prompted.
4. View the results on the console or output file (for file-based operations).

---

## File Requirements
- **Default Input File**: `input.txt` (used for text editing if a custom file isn't provided).
- **Word Dictionary File**: `words.txt` (used for word replacements).

---

## Compilation
To compile:
```bash
g++ -o MultiPurposeUtilityProgram main.cpp
