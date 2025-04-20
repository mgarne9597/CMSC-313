## AUTHORS
Matt Garner UMBC/CMSC-313 4/19/2025

---

## PURPOSE OF SOFTWARE
The purpose of this project is to show basic matrix operations implemented in both C++ and C. 
The operations include matrix creation, addition, scalar multiplication, transposition, and multiplication. 

---

## FILES
- **matrix_demo.c**:  
  Contains the C implementation of matrix operations. Includes functions for creating, manipulating, and freeing matrices.

- **matrix_demo.cpp**:  
  Contains the C++ implementation of matrix operations using a Matrix class. Includes methods for matrix creation, addition, scalar multiplication, transposition, and multiplication.

- **Makefile**:  
  Automates the build process for both the C and C++ implementations. Provides targets to compile the programs and clean up generated files.

---

## BUILD INSTRUCTIONS
1. Ensure you have gcc and g++ installed on your system.
2. If using Windows, ensure mingw32-make is installed and available in your PATH.
3. Open a terminal and cd to the directory containing the files.
4. Run the following commands to build the C and C++ programs:
   mingw32-make matrix_demo_cpp (for c++ file)
   mingw32-make matrix_demo_c (for c file)
5. Run the executables by using the file names in the terminal
   matrix_demo_cpp
   matrix_demo_c

---

## TESTING METHODOLOGY
The programs include hardcoded matrices for testing. These matrices are printed to the console to verify correctness at each step of the operations.

Step-by-Step Output:
Each step of the matrix operations (scalar multiplication, transposition, and addition) is printed to the console to ensure the intermediate results are correct.

Memory Management:
The C implementation ensures proper allocation and deallocation of memory for matrices. The freeMatrix function is used to prevent memory leaks.

Comparison of Results:
The outputs of the C and C++ implementations can be compared to ensure consistency between the two versions.

Edge Cases:
The programs handle edge cases such as mismatched matrix dimensions for addition or multiplication by printing error messages.
