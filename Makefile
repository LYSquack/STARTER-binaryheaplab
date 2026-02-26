# Makefile for binary heap lab

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# default target
all: examheap

# simple test program that just links heap.o (for manual testing)
# (not used since there is no main in heap.cpp)
#heap_test: heap.o
#	$(CXX) $(CXXFLAGS) -o heap_test heap.o

# the more involved test driver
examheap: examheap.o heap.o
	$(CXX) $(CXXFLAGS) -o examheap examheap.o heap.o

# object files
heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp

examheap.o: examheap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c examheap.cpp

# clean up
clean:
	rm -f *.o heap_test examheap

.PHONY: all clean
