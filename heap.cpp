// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
    vdata.push_back(value);
    bubble_up(vdata.size() - 1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    if (vdata.empty()) return;
    // move last element to root, remove min
    vdata[0] = vdata.back();
    vdata.pop_back();
    if (!vdata.empty())
        bubble_down(0);
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.empty()){
      // undefined behaviour in original spec; return 0
      return 0;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    
// helper implementations ----------------------------------

void Heap::bubble_down(int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

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

void Heap::bubble_up(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (vdata[index] < vdata[parent]) {
            std::swap(vdata[index], vdata[parent]);
            index = parent;
        } else {
            break;
        }
    }
}
