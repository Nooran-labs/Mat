// noorangnaim@gmail.com
#ifndef SQUAREMAT_H
#define SQUAREMAT_H

#include <iostream>
using namespace std;

class SquareMat {
private:
    double** mat;
    int degree;

public:
    // Constructor, Destructor, Copy constructor, Assignment operator
    SquareMat(int degree);
    ~SquareMat();
    SquareMat(const SquareMat& other);
    SquareMat& operator=(const SquareMat& other);

    // Member access
    double* operator[](int row);
    const double* operator[](int row) const;

    // In-place modification operators
    void operator~();
    void operator-();
    void operator+=(const SquareMat& other);
    void operator-=(const SquareMat& other);
    void operator*=(const SquareMat& other);
    void operator*=(double scalar);
    void operator/=(double scalar);
    void operator%=(const SquareMat& other);
    void operator%=(int scalar);

    // Return new matrix operators
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator*(double scalar) const;
    SquareMat operator/(double scalar) const;
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator^(int power) const;

    // Increment/Decrement operators
    SquareMat& operator++();     // Pre-increment
    SquareMat operator++(int);   // Post-increment
    SquareMat& operator--();     // Pre-decrement
    SquareMat operator--(int);   // Post-decrement

    // Comparison operators
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;

    // Determinant operator
    double operator!() const;

    // Friend functions
    friend SquareMat operator*(double scalar, const SquareMat& mat);
    friend ostream& operator<<(ostream& os, const SquareMat& mat);

    // Other methods
    void set(int row, int col, double value);
    double get(int row, int col) const;
    int getDegree() const;
    void print() const;
};

#endif
