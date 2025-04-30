// noorangnaim@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"  // Ensure doctest.h is present in the project folder
#include "SquareMat.h"

TEST_CASE("Constructor and getDegree") {
    SquareMat mat(3);
    CHECK(mat.getDegree() == 3);
}

TEST_CASE("Operator [] and set/get") {
    SquareMat mat(2);
    mat[0][0] = 1.5;
    mat[1][1] = 2.5;
    CHECK(mat.get(0,0) == doctest::Approx(1.5));
    CHECK(mat.get(1,1) == doctest::Approx(2.5));
}

TEST_CASE("Addition and in-place addition") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[1][1] = 2;
    b[0][0] = 3; b[1][1] = 4;
    SquareMat sum = a + b;
    CHECK(sum[0][0] == doctest::Approx(4));
    CHECK(sum[1][1] == doctest::Approx(6));
    a += b;
    CHECK(a[0][0] == doctest::Approx(4));
    CHECK(a[1][1] == doctest::Approx(6));
}

TEST_CASE("Subtraction and in-place subtraction") {
    SquareMat a(2), b(2);
    a[0][0] = 5; a[1][1] = 6;
    b[0][0] = 1; b[1][1] = 2;
    SquareMat diff = a - b;
    CHECK(diff[0][0] == doctest::Approx(4));
    CHECK(diff[1][1] == doctest::Approx(4));
    a -= b;
    CHECK(a[0][0] == doctest::Approx(4));
    CHECK(a[1][1] == doctest::Approx(4));
}

TEST_CASE("Scalar operations") {
    SquareMat a(2);
    a[0][0] = 2; a[1][1] = 4;
    SquareMat prod = a * 2;
    CHECK(prod[0][0] == doctest::Approx(4));
    CHECK(prod[1][1] == doctest::Approx(8));
    a *= 0.5;
    CHECK(a[0][0] == doctest::Approx(1));
    CHECK(a[1][1] == doctest::Approx(2));
    a /= 2;
    CHECK(a[0][0] == doctest::Approx(0.5));
    CHECK(a[1][1] == doctest::Approx(1));
}

TEST_CASE("Matrix multiplication and elementwise %") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 2; b[0][1] = 0;
    b[1][0] = 1; b[1][1] = 2;
    SquareMat mult = a * b;
    CHECK(mult[0][0] == doctest::Approx(4));
    CHECK(mult[0][1] == doctest::Approx(4));
    CHECK(mult[1][0] == doctest::Approx(10));
    CHECK(mult[1][1] == doctest::Approx(8));
    SquareMat elem = a % b;
    CHECK(elem[0][0] == doctest::Approx(2));
    CHECK(elem[1][0] == doctest::Approx(3));
}

TEST_CASE("Transpose, unary minus") {
    SquareMat a(2);
    a[0][1] = 3;
    a[1][0] = 7;
    ~a;
    CHECK(a[1][0] == doctest::Approx(3));
    CHECK(a[0][1] == doctest::Approx(7));
    -a;
    CHECK(a[1][0] == doctest::Approx(-3));
    CHECK(a[0][1] == doctest::Approx(-7));
}

TEST_CASE("Modulo operator and element-wise assignment") {
    SquareMat a(2);
    a[0][0] = 10.5; a[1][1] = 7.8;
    SquareMat modded = a % 3;
    CHECK(modded[0][0] == doctest::Approx(10.5 - 3*3));
    CHECK(modded[1][1] == doctest::Approx(7.8 - 3*2));
}

TEST_CASE("Power operator") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 0;
    SquareMat fib = a ^ 5;
    CHECK(fib[0][0] == doctest::Approx(8));
    CHECK(fib[0][1] == doctest::Approx(5));
    CHECK(fib[1][0] == doctest::Approx(5));
    CHECK(fib[1][1] == doctest::Approx(3));
}

TEST_CASE("Comparison and equality") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[1][1] = 3;
    b[0][0] = 2; b[1][1] = 2;
    CHECK(a == b);
    CHECK(!(a != b));
    CHECK(!(a > b));
    CHECK(!(a < b));
    CHECK(a <= b);
    CHECK(a >= b);
}

TEST_CASE("Determinant and output") {
    SquareMat a(2);
    a[0][0] = 4; a[0][1] = 6;
    a[1][0] = 3; a[1][1] = 8;
    CHECK((!a) == doctest::Approx(14.0));

    std::ostringstream out;
    out << a;
    std::string str = out.str();
    CHECK(str.find("4") != std::string::npos);
    CHECK(str.find("6") != std::string::npos);
}
