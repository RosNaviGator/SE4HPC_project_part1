#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

#define seed 2905

void multiplyMatricesWithoutErrors(const std::vector<std::vector<int>> &A,
                      const std::vector<std::vector<int>> &B,
                      std::vector<std::vector<int>> &C, int rowsA, int colsA,
                      int colsB) {
  for (int i = 0; i < rowsA; ++i) {
    for (int j = 0; j < colsB; ++j) {
      C[i][j] = 0;
      for (int k = 0; k < colsA; ++k) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

// Function to generate a random matrix of size rows x cols
std::vector<std::vector<int>> generateRandomMatrix(int rows, int cols, int minValue = -10, int maxValue = 100) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = minValue + (rand() % (maxValue - minValue + 1));
        }
    }

    return matrix;
}


/*
CURRENT ERRORS: 
Error 1: Element-wise multiplication of ones detected!
Error 2: Matrix A contains the number 7!
Error 3: Matrix A contains a negative number!
Error 4: Matrix B contains the number 3!
Error 5: Matrix B contains a negative number!
Error 6: Result matrix contains a number bigger than 100!
Error 7: Result matrix contains a number between 11 and 20!
ERROR 8:
ERROR 9:
ERROR 10:
ERROR 11:
Error 12: The number of rows in A is equal to the number of columns in B!
Error 13: The first element of matrix A is equal to the first element of matrix B!
Error 14: The result matrix C has an even number of rows!
ERROR 15:
Error 16: Matrix B contains the number 6!
ERROR 17:
Error 18: Matrix A is a square matrix!
Error 19: Every row in matrix A contains the number 8!
Error 20: Number of columns in matrix A is odd!

*/

// ######################### Source code of multiplyMatrices in src/matrix_mult

/*  //ERRORS: 6, 12, 14, 20
// Test: already existing matrix multiplication
TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    multiplyMatricesWithoutErrors(A, B, expected, 2, 3, 2);

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}
*/

/*  //ERRORS: 2, 3, 5, 6, 20
// Test for multiplying matrices with random dimensions and values
TEST(MatrixMultiplicationTest, TestRandomMatrixMultiplication) 
{
    srand(seed);  // Seed for random number generation

    // Generate random dimensions for the matrices
    int rowsA = 1 + rand() % 10; // Between 1 and 10
    int colsA = 1 + rand() % 10; // Between 1 and 10
    int colsB = 1 + rand() % 10; // Between 1 and 10

    // Generate random matrices
    std::vector<std::vector<int>> A = generateRandomMatrix(rowsA, colsA);
    std::vector<std::vector<int>> B = generateRandomMatrix(colsA, colsB);
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));
    std::vector<std::vector<int>> expected(rowsA, std::vector<int>(colsB, 0));

    // Multiply the matrices
    multiplyMatrices(A, B, C, rowsA, colsA, colsB);
    multiplyMatricesWithoutErrors(A, B, expected, rowsA, colsA, colsB);

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";


}
*/

/*
TEST()
{
}


*/

/*  //ERRORS: 6, 12, 13, 14, 18, 19
// Test for multiplying squared matrices with same values
TEST(MatrixMultiplicationTest, TestSameNumberMatrixMultiplication) 
{
    srand(seed);  // Seed for random number generation

    // Fixed dimensions for the squared matrices
    int rows = 10;
    int cols = 10;

    for (int sameNumber = 8; sameNumber <= 10; ++sameNumber) 
    {
        // Generate matrix A filled with the same number
        std::vector<std::vector<int>> A(rows, std::vector<int>(cols, sameNumber));

        // Generate matrix B filled with the same number
        std::vector<std::vector<int>> B(rows, std::vector<int>(cols, sameNumber));

        // Initialize the expected result matrix
        std::vector<std::vector<int>> expected(rows, std::vector<int>(cols, sameNumber * sameNumber));

        // Initialize the result matrix
        std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

        // Multiply the matrices
        multiplyMatrices(A, B, result, rows, cols, cols);

        // Check if the result matches the expected result
        ASSERT_EQ(result, expected) << "Matrix multiplication test failed with same number: " << sameNumber;
    }
}
*/

/*  //ERRORS: 1, 2, 12, 13, 14, 18, 19
// Test for multiplying squared matrices with same values
TEST(MatrixMultiplicationTest, TestSameNumberMatrixMultiplication) 
{
    // Fixed dimensions for the squared matrices
    int rows = 10;
    int cols = 10;

    for (int sameNumber = 1; sameNumber <= 10; ++sameNumber) 
    {
        // Generate matrix A filled with sequential numbers from 1 to 10 in each row
        std::vector<std::vector<int>> A(rows, std::vector<int>(cols));
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                A[i][j] = j + 1;
            }
        }

        // Generate matrix B filled with the same number
        std::vector<std::vector<int>> B(rows, std::vector<int>(cols, sameNumber));

        // Initialize the expected result matrix
        std::vector<std::vector<int>> expected(rows, std::vector<int>(cols, sameNumber * 55)); // Sum of numbers from 1 to 10 is 55

        // Initialize the result matrix
        std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

        // Multiply the matrices
        multiplyMatrices(A, B, result, rows, cols, cols);

        // Check if the result matches the expected result
        ASSERT_EQ(result, expected) << "Matrix multiplication test failed with same number: " << sameNumber;
    }
}
*/

/*  //ERRORS: 1, 4, 7, 12, 13, 16, 18, 20
// Test for multiplying a matrix with a zero matrix
TEST(MatrixMultiplicationTest, TestIdentityMatrix)
{
    std::vector<std::vector<int>> A = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    std::vector<std::vector<int>> expected(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    multiplyMatricesWithoutErrors(A, B, expected, 3, 3, 3);

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}
*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
