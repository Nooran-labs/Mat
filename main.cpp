// noorangnaim@gmail.com
#include "SquareMat.h"
#include <iostream>
using namespace std;

int main() {
    // Create two 3x3 matrices
    SquareMat mat1(3);
    SquareMat mat2(3);

    // Set values for mat1 using operator[]
    mat1[0][0] = 1.0; mat1[0][1] = 2.0; mat1[0][2] = 3.0;
    mat1[1][0] = 4.0; mat1[1][1] = 5.0; mat1[1][2] = 6.0;
    mat1[2][0] = 7.0; mat1[2][1] = 8.0; mat1[2][2] = 9.0;

    // Set values for mat2 using operator[]
    mat2[0][0] = 9.0; mat2[0][1] = 8.0; mat2[0][2] = 7.0;
    mat2[1][0] = 6.0; mat2[1][1] = 5.0; mat2[1][2] = 4.0;
    mat2[2][0] = 3.0; mat2[2][1] = 2.0; mat2[2][2] = 1.0;

    cout << "Matrix 1:\n" << mat1;
    cout << "Matrix 2:\n" << mat2;

    // Demonstrate + operator
    cout << "Matrix 1 + Matrix 2:\n" << (mat1 + mat2);

    // Demonstrate - operator
    cout << "Matrix 1 - Matrix 2:\n" << (mat1 - mat2);

    // Demonstrate matrix multiplication
    cout << "Matrix 1 * Matrix 2:\n" << (mat1 * mat2);

    // Scalar multiplication
    cout << "Matrix 1 * 2.0:\n" << (mat1 * 2.0);
    cout << "2.0 * Matrix 1:\n" << (2.0 * mat1);

    // Element-wise multiplication
    cout << "Element-wise multiplication (Matrix 1 % Matrix 2):\n" << (mat1 % mat2);

    // Modulo with scalar
    cout << "Matrix 1 % 5:\n" << (mat1 % 5);

    // Division by scalar
    cout << "Matrix 1 / 2.0:\n" << (mat1 / 2.0);

    // Power operator
    cout << "Matrix 1 ^ 2:\n" << (mat1 ^ 2);

    // Demonstrate in-place operators
    mat1 += mat2;
    cout << "Matrix 1 after += Matrix 2:\n" << mat1;

    mat1 -= mat2;
    cout << "Matrix 1 after -= Matrix 2:\n" << mat1;

    mat1 *= mat2;
    cout << "Matrix 1 after *= Matrix 2:\n" << mat1;

    mat1 *= 0.5;
    cout << "Matrix 1 after *= 0.5:\n" << mat1;

    mat1 /= 2.0;
    cout << "Matrix 1 after /= 2.0:\n" << mat1;

    mat1 %= mat2;
    cout << "Matrix 1 after %= Matrix 2:\n" << mat1;

    mat1 %= 3;
    cout << "Matrix 1 after %= 3:\n" << mat1;

    // Transpose
    ~mat1;
    cout << "Matrix 1 after transpose:\n" << mat1;

    // Unary minus
    -mat1;
    cout << "Matrix 1 after unary minus:\n" << mat1;

    // Increment and Decrement
    cout << "Matrix 1 after pre-increment:\n" << ++mat1;
    cout << "Matrix 1 after post-increment:\n" << mat1++;
    cout << "Matrix 1 now:\n" << mat1;

    cout << "Matrix 1 after pre-decrement:\n" << --mat1;
    cout << "Matrix 1 after post-decrement:\n" << mat1--;
    cout << "Matrix 1 now:\n" << mat1;

    // Comparisons
    cout << "Matrix 1 == Matrix 2? " << (mat1 == mat2 ? "Yes" : "No") << endl;
    cout << "Matrix 1 != Matrix 2? " << (mat1 != mat2 ? "Yes" : "No") << endl;
    cout << "Matrix 1 > Matrix 2? " << (mat1 > mat2 ? "Yes" : "No") << endl;
    cout << "Matrix 1 < Matrix 2? " << (mat1 < mat2 ? "Yes" : "No") << endl;

    // Determinant
    cout << "Determinant of Matrix 2: " << !mat2 << endl;

    return 0;
}
