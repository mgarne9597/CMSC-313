#include <stdio.h>
#include <stdlib.h>

// Written by Matt Garner for CMSC-313 HW #8
// Matrix structure
typedef struct {
    double** data;
    int rows;
    int cols;
} Matrix;

// Create a new matrix with given dimensions and initial value
Matrix createMatrix(int rows, int cols, double initialValue) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    
    // Allocate memory for rows
    m.data = (double**)malloc(rows * sizeof(double*));
    
    // Allocate memory for columns and initialize
    for (int i = 0; i < rows; i++) {
        m.data[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = initialValue;
        }
    }
    
    return m;
}

// Free memory allocated for matrix
void freeMatrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);
}

// Set matrix element at position (row, col)
void setElement(Matrix m, int row, int col, double value) {
    if (row >= 0 && row < m.rows && col >= 0 && col < m.cols) {
        m.data[row][col] = value;
    }
}

// Get matrix element at position (row, col)
double getElement(Matrix m, int row, int col) {
    if (row >= 0 && row < m.rows && col >= 0 && col < m.cols) {
        return m.data[row][col];
    }
    return 0.0; // Default return if out of bounds
}

// Add two matrices
Matrix addMatrices(Matrix a, Matrix b) {
    // Check if dimensions match
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Cannot add matrices with different dimensions\n");
        return createMatrix(0, 0, 0.0); // Return empty matrix
    }
    
    Matrix result = createMatrix(a.rows, a.cols, 0.0);
    
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    
    return result;
}

// Multiply matrix by scalar
Matrix multiplyByScalar(Matrix m, double scalar) {
    Matrix result = createMatrix(m.rows, m.cols, 0.0);
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[i][j] = m.data[i][j] * scalar;
        }
    }
    
    return result;
}

// Transpose matrix
Matrix transposeMatrix(Matrix m) {
    Matrix result = createMatrix(m.cols, m.rows, 0.0);
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[j][i] = m.data[i][j];
        }
    }
    
    return result;
}

// Multiply two matrices
Matrix multiplyMatrices(Matrix a, Matrix b) {
    // Check if dimensions are compatible for multiplication
    if (a.cols != b.rows) {
        printf("Error: Cannot multiply matrices with incompatible dimensions\n");
        return createMatrix(0, 0, 0.0); // Return empty matrix
    }
    
    Matrix result = createMatrix(a.rows, b.cols, 0.0);
    
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    
    return result;
}

// Print matrix
void printMatrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        printf("[");
        for (int j = 0; j < m.cols; j++) {
            printf("%.1f", m.data[i][j]);
            if (j < m.cols - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int main() {
    // Create matrices A, B, and C as defined in the problem
    printf("Creating matrices A, B, and C...\n");
    
    // Matrix A (2x2)
    Matrix A = createMatrix(2, 2, 0.0);
    setElement(A, 0, 0, 6.0);
    setElement(A, 0, 1, 4.0);
    setElement(A, 1, 0, 8.0);
    setElement(A, 1, 1, 3.0);
    printf("Matrix A:\n");
    printMatrix(A);
    printf("\n");
    
    // Matrix B (2x3)
    Matrix B = createMatrix(2, 3, 0.0);
    setElement(B, 0, 0, 1.0);
    setElement(B, 0, 1, 2.0);
    setElement(B, 0, 2, 3.0);
    setElement(B, 1, 0, 4.0);
    setElement(B, 1, 1, 5.0);
    setElement(B, 1, 2, 6.0);
    printf("Matrix B:\n");
    printMatrix(B);
    printf("\n");
    
    // Matrix C (2x3)
    Matrix C = createMatrix(2, 3, 0.0);
    setElement(C, 0, 0, 2.0);
    setElement(C, 0, 1, 4.0);
    setElement(C, 0, 2, 6.0);
    setElement(C, 1, 0, 1.0);
    setElement(C, 1, 1, 3.0);
    setElement(C, 1, 2, 5.0);
    printf("Matrix C:\n");
    printMatrix(C);
    printf("\n");
    
    // Calculate D = A + (3 * B) × C^T
    printf("Calculating D = A + (3 * B) * C^T...\n");
    
    // Step 1: Calculate 3 * B
    printf("Step 1: 3 * B\n");
    Matrix scaledB = multiplyByScalar(B, 3.0);
    printMatrix(scaledB);
    printf("\n");
    
    // Step 2: Calculate C^T (transpose of C)
    printf("Step 2: C^T (transpose of C)\n");
    Matrix transposedC = transposeMatrix(C);
    printMatrix(transposedC);
    printf("\n");
    
    // Step 3: Calculate (3 * B) × C^T
    printf("Step 3: (3 * B) * C^T\n");
    Matrix product = multiplyMatrices(scaledB, transposedC);
    printMatrix(product);
    printf("\n");
    
    // Step 4: Calculate A + (3 * B) × C^T
    printf("Step 4: A + (3 * B) * C^T\n");
    Matrix D = addMatrices(A, product);
    printf("Result (D):\n");
    printMatrix(D);
    
    // Free allocated memory
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(scaledB);
    freeMatrix(transposedC);
    freeMatrix(product);
    freeMatrix(D);
    
    return 0;
}