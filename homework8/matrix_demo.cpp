#include <iostream>
#include <vector>
using namespace std;

// Written by Matt Garner for CMSC-313 HW #8
// Simple Matrix class with basic operations
class Matrix {
private:
    vector<vector<double>> data;
    int rows;
    int cols;

public:
    // Constructor with dimensions and initial value
    Matrix(int r, int c, double initialValue = 0.0) {
        rows = r;
        cols = c;
        data.resize(rows, vector<double>(cols, initialValue));
    }

    // Constructor from vector of vectors
    Matrix(const vector<vector<double>>& inputData) {
        rows = inputData.size();
        cols = inputData[0].size();
        data = inputData;
    }

    // Get number of rows
    int getRows() {
        return rows;
    }

    // Get number of columns
    int getCols() {
        return cols;
    }

    // Access element at position (row, col)
    double& at(int row, int col) {
        return data[row][col];
    }

    // Matrix addition
    Matrix add(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Scalar multiplication
    Matrix multiply(double scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Matrix transposition
    Matrix transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix multiply(const Matrix& other) {
        Matrix result(rows, other.cols, 0.0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Display the matrix
    void print() {
        for (int i = 0; i < rows; i++) {
            cout << "[";
            for (int j = 0; j < cols; j++) {
                cout << data[i][j];
                if (j < cols - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    // Create matrices A, B, and C as defined in the problem
    cout << "Creating matrices A, B, and C..." << endl;
    
    // Matrix A (2x2)
    vector<vector<double>> dataA = {
        {6.0, 4.0},
        {8.0, 3.0}
    };
    Matrix A(dataA);
    cout << "Matrix A:" << endl;
    A.print();
    cout << endl;
    
    // Matrix B (2x3)
    vector<vector<double>> dataB = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}
    };
    Matrix B(dataB);
    cout << "Matrix B:" << endl;
    B.print();
    cout << endl;
    
    // Matrix C (2x3)
    vector<vector<double>> dataC = {
        {2.0, 4.0, 6.0},
        {1.0, 3.0, 5.0}
    };
    Matrix C(dataC);
    cout << "Matrix C:" << endl;
    C.print();
    cout << endl;
    
    // Calculate D = A + (3 * B) × C^T
    cout << "Calculating D = A + (3 * B) * C^T..." << endl;
    
    // Step 1: Calculate 3 * B
    cout << "Step 1: 3 * B" << endl;
    Matrix scaledB = B.multiply(3.0);
    scaledB.print();
    cout << endl;
    
    // Step 2: Calculate C^T (transpose of C)
    cout << "Step 2: C^T (transpose of C)" << endl;
    Matrix transposedC = C.transpose();
    transposedC.print();
    cout << endl;
    
    // Step 3: Calculate (3 * B) × C^T
    cout << "Step 3: (3 * B) * C^T" << endl;
    Matrix product = scaledB.multiply(transposedC);
    product.print();
    cout << endl;
    
    // Step 4: Calculate A + (3 * B) × C^T
    cout << "Step 4: A + (3 * B) * C^T" << endl;
    Matrix D = A.add(product);
    cout << "Result (D):" << endl;
    D.print();
    
    return 0;
}
