//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
         if (size >= 64) return; //If the heap is full, do nothing.
        data[size] = idx; //insert data at end
        upheap(size, weightArr); //Upheap it to restore the order of the heap.
        size++; //Increase heap size/increment.
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) return -1;
        int root = data[0];//This is the root value.
        size--;//Decrement size.
        if (size > 0) { //Move the last element to the root and now downheap.
            data[0] = data[size];
            downheap(0, weightArr);
        }
        return root; //return the value of root.
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif