# noorangnaim@gmail.com
# SquareMat Project
CXX = g++
CXXFLAGS = -g -Wall
SRC = SquareMat.cpp
HEADERS = SquareMat.h

# Default target
all: main

main: main.cpp $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) main.cpp $(SRC) -o main

test: test_squaremat.cpp $(SRC) $(HEADERS) doctest.h
	$(CXX) $(CXXFLAGS) test_squaremat.cpp $(SRC) -o test

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all ./test

clean:
	rm -f main test *.o *.out *.exe

