# Compiler settings
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11
CXXFLAGS = -Wall -Wextra -std=c++11

# Targets
all: matrix_demo_c matrix_demo_cpp

# C implementation
matrix_demo_c: matrix_demo.c
	$(CC) $(CFLAGS) -o matrix_demo_c matrix_demo.c -lm

# C++ implementation
matrix_demo_cpp: matrix_demo.cpp
	$(CXX) $(CXXFLAGS) -o matrix_demo_cpp matrix_demo.cpp

# Clean
clean:
	rm -f matrix_demo_c matrix_demo_cpp

.PHONY: all clean