// noorangnaim@gmail.com
#include "SquareMat.h"
#include <iostream>
using namespace std;


SquareMat::SquareMat(int degree) : degree(degree) {
    mat = new double*[degree];
    for (int i = 0; i < degree; ++i) {
        mat[i] = new double[degree];
        for (int j = 0; j < degree; ++j) {
            mat[i][j] = 0.0;
        }
    }
}

SquareMat::~SquareMat() {
    for (int i = 0; i < degree; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

SquareMat::SquareMat(const SquareMat& other) : degree(other.degree) {
    mat = new double*[degree];
    for (int i = 0; i < degree; ++i) {
        mat[i] = new double[degree];
        for (int j = 0; j < degree; ++j) {
            mat[i][j] = other.mat[i][j];
        }
    }
}

SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this == &other) return *this;

    for (int i = 0; i < degree; ++i)
        delete[] mat[i];
    delete[] mat;

    degree = other.degree;
    mat = new double*[degree];
    for (int i = 0; i < degree; ++i) {
        mat[i] = new double[degree];
        for (int j = 0; j < degree; ++j) {
            mat[i][j] = other.mat[i][j];
        }
    }
    return *this;
}

double* SquareMat::operator[](int row) {
    return mat[row];
}

const double* SquareMat::operator[](int row) const {
    return mat[row];
}

void SquareMat::operator~() {
    for (int i = 0; i < degree; ++i) {
        for (int j = i + 1; j < degree; ++j) {
            double temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void SquareMat::operator-() {
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            mat[i][j] = -mat[i][j];
}

void SquareMat::operator+=(const SquareMat& other) {
    if (degree != other.degree){
     std::cerr << "Error: Matrix sizes must match for += operation." << std::endl; 
     exit(1);
     }
    if (degree != other.degree) return;
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            mat[i][j] += other.mat[i][j];
}

void SquareMat::operator-=(const SquareMat& other) {
    if (degree != other.degree){
     std::cerr << "Error: Matrix sizes must match for -= operation." << std::endl; 
     exit(1);
     }
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            mat[i][j] -= other.mat[i][j];
}

void SquareMat::operator*=(const SquareMat& other) {
    if (degree != other.degree){
     std::cerr << "Error: Matrix sizes must match for *= operation." << std::endl;
     exit(1);
     }
    *this = *this * other;
}

void SquareMat::operator*=(double scalar) {
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            mat[i][j] *= scalar;
}

void SquareMat::operator/=(double scalar) {
    if (scalar == 0){
     std::cerr << "Error: You can't divide by 0" << std::endl;
     exit(1);
     }
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            mat[i][j] /= scalar;
}

void SquareMat::operator%=(const SquareMat& other) {
    if (degree != other.degree){
     std::cerr << "Error: Matrix sizes must match for %= operation." << std::endl; 
     exit(1);
     }
    if (degree != other.degree) return;
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            mat[i][j] *= other.mat[i][j];
}

void SquareMat::operator%=(int scalar) {
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j) {
            double val = mat[i][j];
            int quotient = (int)(val / scalar);
            mat[i][j] = val - scalar * quotient;
        }
}

SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (degree != other.degree){
    std::cerr << "Error: Matrix sizes must match for + operation." << std::endl; 
    exit(1);
    }
    SquareMat result(degree);
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            result.mat[i][j] = mat[i][j] + other.mat[i][j];
    return result;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (degree != other.degree){
    std::cerr << "Error: Matrix sizes must match for - operation." << std::endl; 
    exit(1);
    }
    SquareMat result(degree);
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            result.mat[i][j] = mat[i][j] - other.mat[i][j];
    return result;
}

SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (degree != other.degree){ 
    std::cerr << "Error: Matrix sizes must match for * operation." << std::endl; 
    exit(1);
    }
    SquareMat result(degree);
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            for (int k = 0; k < degree; ++k)
                result.mat[i][j] += mat[i][k] * other.mat[k][j];
    return result;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(degree);
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            result.mat[i][j] = mat[i][j] * scalar;
    return result;
}

SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;
}

SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (degree != other.degree){ 
    std::cerr << "Error: Matrix sizes must match for % operation." << std::endl; 
    exit(1);
    }
    SquareMat result(degree);
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            result.mat[i][j] = mat[i][j] * other.mat[i][j];
    return result;
}

SquareMat SquareMat::operator%(int scalar) const {
    SquareMat result(degree);
    for (int i = 0; i < degree; ++i) {
        for (int j = 0; j < degree; ++j) {
            double val = mat[i][j];
            int quotient = (int)(val / scalar);
            result.mat[i][j] = val - scalar * quotient;
        }
    }
    return result;
}

SquareMat SquareMat::operator/(double scalar) const {
    SquareMat result(degree);
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            result.mat[i][j] = mat[i][j] / scalar;
    return result;
}

SquareMat SquareMat::operator^(int power) const {
    SquareMat result(degree);
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            result.mat[i][j] = (i == j) ? 1.0 : 0.0; // Identity

    SquareMat base(*this);
    while (power > 0) {
        if (power % 2 == 1)
            result = result * base;
        base = base * base;
        power /= 2;
    }
    return result;
}

// Increment and Decrement Operators
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            ++mat[i][j];
    return *this;
}

SquareMat SquareMat::operator++(int) {
    SquareMat temp(*this);
    ++(*this);
    return temp;
}

SquareMat& SquareMat::operator--() {
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j)
            --mat[i][j];
    return *this;
}

SquareMat SquareMat::operator--(int) {
    SquareMat temp(*this);
    --(*this);
    return temp;
}

// Comparison Operators
bool SquareMat::operator==(const SquareMat& other) const {
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j) {
            sum1 += mat[i][j];
            sum2 += other.mat[i][j];
        }
    return sum1 == sum2;
}

bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

bool SquareMat::operator<(const SquareMat& other) const {
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < degree; ++i)
        for (int j = 0; j < degree; ++j) {
            sum1 += mat[i][j];
            sum2 += other.mat[i][j];
        }
    return sum1 < sum2;
}

bool SquareMat::operator<=(const SquareMat& other) const {
    return (*this < other) || (*this == other);
}

bool SquareMat::operator>(const SquareMat& other) const {
    return !(*this <= other);
}

bool SquareMat::operator>=(const SquareMat& other) const {
    return !(*this < other);
}

// Determinant Operator
static double determinant(double** matrix, int n) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0;
    double** temp = new double*[n];
    for (int i = 0; i < n; ++i) temp[i] = new double[n];

    int sign = 1;
    for (int f = 0; f < n; ++f) {
        int subi = 0;
        for (int i = 1; i < n; ++i) {
            int subj = 0;
            for (int j = 0; j < n; ++j) {
                if (j == f) continue;
                temp[subi][subj++] = matrix[i][j];
            }
            subi++;
        }
        det += sign * matrix[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    for (int i = 0; i < n; ++i) delete[] temp[i];
    delete[] temp;

    return det;
}

double SquareMat::operator!() const {
    return determinant(mat, degree);
}

// Output Operator
ostream& operator<<(ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.degree; ++i) {
        for (int j = 0; j < mat.degree; ++j) {
            os << mat.mat[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
void SquareMat::set(int row, int col, double value) {
    if (row >= 0 && row < degree && col >= 0 && col < degree) {
        mat[row][col] = value;
    }
}

double SquareMat::get(int row, int col) const {
    if (row >= 0 && row < degree && col >= 0 && col < degree) {
        return mat[row][col];
    }
    return 0.0;
}

int SquareMat::getDegree() const {
    return degree;
}


