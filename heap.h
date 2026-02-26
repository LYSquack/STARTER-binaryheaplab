// heap.h
// Binary heap tree header file for CS 24 lab
// Yusen Liu

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap{

 public:
    Heap() = default;            // default constructor creates empty heap
    void push(int value);     // insert value; //duplicates are allowed
    void pop(); // delete the min element 
    int top();
    bool empty();
    Heap(std::vector<int>::iterator start, std::vector<int>::iterator end) {
        // copy range into internal vector
        vdata.assign(start, end);
        // run Floyd's heapify algorithm: bubble down each non-leaf node
        // starting from the last parent and moving backwards to 0.
        // note: when vdata.size()==0 or 1 there's nothing to do.
        if (vdata.size() > 1) {
            // size_t is unsigned; use a reverse loop that handles zero correctly.
            for (std::size_t i = vdata.size() / 2; i-- > 0; ) {
                bubble_down(i);
            }
        }
    }

    
 private:
    std::vector<int> vdata; //store the binary heap tree as a dynamic array

    // helpers to restore heap property after insert/remove
    void bubble_down(std::size_t index);
    void bubble_up(std::size_t index);
};

#endif