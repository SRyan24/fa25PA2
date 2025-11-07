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
        // X: insert index at end of heap, restore order using upheap()
        //Insert index at end
        data[size] = idx;
        //Restore Order & update size
        upheap(size, weightArr);
        size++;

    }

    int pop(int weightArr[]) {
        // X: remove and return smallest index
        // Replace root with last element, then call downheap()

        //If empty, return -1;
        if (size == 0) {
            return -1;
        }

        // temp smallest index assigned first data, then replaced
        int minIdx = data [0];
        data[0] = data[size - 1];
        size--;

        //Restore order
        downheap(0, weightArr);

        // Smallest index (removed in process)
        return minIdx;
    }

    void upheap(int pos, int weightArr[]) { // CHANGED weightArr[] to const
        // DONE: swap child upward while smaller than parent
        //Continuous upheap until sorted
        while (pos > 0) {
            // ( i - 1 ) /2 : index formula
            int parent = (pos - 1)/2;

            // check if child is smaller, swap pos with parent if necessary to maintain order
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            } else { break;} // LACK OF BREAK STATEMENT LEFT HUGE ERROR !!
        }
    }

    void downheap(int pos, int weightArr[]) { // CHANGED weightArr[] to const
        // X: swap parent downward while larger than any child
        while (true) {
            // (i*2)+(1 or 2) Child position formula
            int childL = (pos*2)+1;
            int childR = (pos*2)+2;
            int smallest = pos; //Temp assignment to be checked

            //Find which child is smaller, assign to smallest
            if (childL < size && weightArr[data[childL]] < weightArr[data[smallest]]) {
                smallest = childL;
            }
            if (childR < size && weightArr[data[childR]] < weightArr[data[smallest]]) {
                smallest = childR;
            }

            // if neither is smaller, swap position regardless, else finished
            if (smallest != pos) {
                swap(data[pos], data[smallest]);
                pos = smallest;
            } else {
                break;
            }

        }
    }
};

#endif