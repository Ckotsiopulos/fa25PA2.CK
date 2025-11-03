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
        int child = pos;

        // Check while child has parent
        while (child > 0) {

            int parent = (child - 1) / 2;

            // compare the data at child and parent
            int c = data[child];
            int p = data[parent];

            // If child is smaller than parent, swap
            if (weightArr[c] < weightArr[p]) {

                int temp = data[child];
                data[child] = data[parent];
                data[parent] = temp;

                // Move child upward
                child = parent;

            } else {
                
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int parent = pos;

        while (true) {

            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int smallest = parent;

            // Check left child
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }

            // Check right child
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }

            // If parent is smallest return
            if (smallest == parent) break;

            // Swap parent with smallest child
            int temp = data[parent];
            data[parent] = data[smallest];
            data[smallest] = temp;

            // Go down
            parent = smallest;
        }
    
    }
};

#endif