# SquareMat Project in C++

## Overview

This project is a C++ implementation of a **square matrix class** (`SquareMat`) without using the STL.  
It supports core matrix operations, arithmetic, and logical features using manually allocated 2D arrays and operator overloading.

All operations are **tested with `doctest`** and memory-safe. The project also includes a demonstration and unit testing system.

---

## File Structure

```plaintext
.
├── SquareMat.h                # SquareMat class declaration
├── SquareMat.cpp              # SquareMat class implementation
├── main.cpp                   # Demonstration and usage examples
├── test_squaremat.cpp         # Unit tests using doctest 
├── doctest.h                  # Lightweight single-header unit testing framework
├── Makefile                   # Automates building, testing, and memory checking
```

---

## SquareMat Class

The `SquareMat` class represents a **fixed-size N x N matrix** of `double` values. It uses raw pointers for memory management and supports various matrix operations.

### Key Features

- Element access via `[][]` operator.
- Memory-safe copy constructor, destructor, and assignment operator.
- Automatic bounds-safe resizing in assignment.

### Supported Operations

#### Arithmetic

- `+`, `-`, `*` — Matrix addition, subtraction, and multiplication.
- `/` — Scalar division.
- `%` — Element-wise matrix multiplication and scalar modulo.
- `^` — Matrix raised to integer power.
- `+=`, `-=`, `*=`, `/=`, `%=` — In-place versions.

#### Logic & Utilities

- `==`, `!=` — Equality based on sum of elements.
- `<`, `<=`, `>`, `>=` — Comparisons based on total element sum.
- `++`, `--` — Pre/post increment and decrement (add/sub 1 to each element).
- `!` — Determinant (up to 3x3).
- `~` — Transpose in-place.
- Unary `-` — Negates all elements in-place.
- `<<` — Output operator to print the matrix.

---

## Makefile Commands

This project includes a `Makefile` with the following targets:

- `make main` – Compiles and runs the main demonstration (`main.cpp`).
- `make test` – Compiles and runs unit tests using `doctest`.
- `make valgrind` – Checks for memory leaks on the test binary using Valgrind.
- `make clean` – Removes all compiled binaries and temporary files.

---

## How to Run

Ensure you have `g++` and Valgrind installed.

```bash
make main       # Run demo
make test       # Run tests
make valgrind   # Check for memory leaks
make clean      # Clean build files
```

---

## Dependencies

- [`doctest.h`](https://github.com/doctest/doctest) – Lightweight testing header (already included).

---

## Educational Purpose

This project is built to explore **manual memory management, operator overloading**, and core C++ matrix operations — without the use of STL.

