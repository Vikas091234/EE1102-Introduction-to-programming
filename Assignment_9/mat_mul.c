/*
Course      : EE1103 - Numerical Methods
Assignment  : 9
Program     : Matrix Multiplication

Description :
Multiplies a 4x5 matrix with a 5x3 matrix using
static two-dimensional arrays and stores the result
in a 4x3 matrix.

Author      : Vikas Raj
*/


#include <stdio.h>

#define ROW_A 4
#define COL_A 5
#define ROW_B 5
#define COL_B 3
#define ROW_RESULT 4
#define COL_RESULT 3

// ---------------------------------------------------------------------------
// Function: myMatMul
// Purpose : Multiply matrix A (4×5) with matrix B (5×3) and store result in
//           the matrix 'result' of size (4×3).
//
// Expected shapes:
//    A: 4 rows × 5 columns
//    B: 5 rows × 3 columns
//    result: 4 rows × 3 columns
//
// Formula:
//    result[i][j] = Σ ( A[i][k] * B[k][j] ) for k = 0 to 4
//
// This function assumes the dimensions are valid and matching, based on the
// #defines given above.
// ---------------------------------------------------------------------------
void myMatMul(float A[ROW_A][COL_A], float B[ROW_B][COL_B], float result[ROW_RESULT][COL_RESULT]) {

    // For each row in A
    for (int i = 0; i < ROW_RESULT; ++i) {

        // For each column in B
        for (int j = 0; j < COL_RESULT; ++j) {

            // Initialize the result element to 0 before accumulating
            result[i][j] = 0;

            // Perform the dot-product between row i of A and column j of B
            for (int k = 0; k < COL_A; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    float matrixA[ROW_A][COL_A];
    float matrixB[ROW_B][COL_B];
    float result[ROW_RESULT][COL_RESULT];

    // -----------------------------------------------------------------------
    // Input elements of matrix A (4×5)
    // -----------------------------------------------------------------------
    printf("Enter elements for matrix A (%d x %d):\n", ROW_A, COL_A);
    for (int i = 0; i < ROW_A; ++i) {
        for (int j = 0; j < COL_A; ++j) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%f", &matrixA[i][j]);
        }
    }

    // -----------------------------------------------------------------------
    // Input elements of matrix B (5×3)
    // -----------------------------------------------------------------------
    printf("Enter elements for matrix B (%d x %d):\n", ROW_B, COL_B);
    for (int i = 0; i < ROW_B; ++i) {
        for (int j = 0; j < COL_B; ++j) {
            printf("Enter element B[%d][%d]: ", i, j);
            scanf("%f", &matrixB[i][j]);
        }
    }

    // -----------------------------------------------------------------------
    // Perform matrix multiplication
    // -----------------------------------------------------------------------
    myMatMul(matrixA, matrixB, result);

    // -----------------------------------------------------------------------
    // Print the resulting matrix (4×3)
    // -----------------------------------------------------------------------
    printf("\nResultant matrix after multiplication:\n");
    for (int i = 0; i < ROW_RESULT; ++i) {
        for (int j = 0; j < COL_RESULT; ++j) {
            printf("%.2f\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
