// heap.cpp
// Yusen Liu

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
    vdata.push_back(value); 
    bubble_up(vdata.size() - 1); //last index of the vector
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    if (vdata.empty()) {
      return;
    }
    vdata[0] = vdata.back(); 
    vdata.pop_back(); 
    bubble_down(0); //we need to restore heap property
}

// Returns the minimum element in the heap
int Heap::top(){
    if (vdata.empty()) {
      throw std::runtime_error("Heap is empty") ; 
    }
    return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
    return vdata.empty(); 
}
    
// helper implementations ----------------------------------

void Heap::bubble_down(std::size_t index) {
    std::size_t smallest = index;
    std::size_t left = 2*index + 1;
    std::size_t right = 2*index + 2;

    if (left < vdata.size() && vdata[left] < vdata[smallest]) {
        smallest = left;
    }
    if (right < vdata.size() && vdata[right] < vdata[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        std::swap(vdata[index], vdata[smallest]);
        bubble_down(smallest);
    }
}

void Heap::bubble_up(std::size_t index) {
    if (index == 0) {
      return;
    }
    while (index > 0) {
      std::size_t parent = (index - 1) / 2;
      if (vdata[index] < vdata[parent]) {
        std::swap(vdata[index], vdata[parent]);
        index = parent;
      } 
      else {
        break;
      }
    }
}
