#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <ostream>
#include <__ranges/elements_view.h>

class MinHeap {
public:
    MinHeap(int capacity) {
        // size 0 at first
        this->capacity = capacity;
        size = 0;

        // make arrays based off of capacitu given
        heapArray = new int[capacity];
        position = new int[capacity];
        keyArray = new int[capacity];

        // goes in and sets everything to infinity at first
        for (int i = 0; i < capacity; i++) {
            keyArray[i] = INT_MAX;
        }
        // after loop puts back keyArrays first element to 0
        keyArray[0] = 0;

        // initializes position with whatever vertexes there is
        for (int i = 0; i < capacity; i++) {
            position[i] = i;
        }
        // initlaizes heapArray with whatever vertexes there is
        for (int i = 0; i < capacity; i++) {
            heapArray[i] = i;
        }
    }
    ~MinHeap() { // destructor to get rid of everything
        delete[] heapArray;
        delete[] position;
        delete[] keyArray;

    };
    void insert(int vertex, int key) {
        // if size is bigger than capacity, cannot insert anything else so return
        if (size >= capacity) {
            return;
        }

        // if not in minheap
        if (isInMinHeap(vertex) == false) {
            // insert info into all three arrays
            heapArray[size] = vertex;
            position[vertex] = size;
            keyArray[vertex] = key;




            // maintain heap after insertion
            minHeapify(size);

            // upsize so can add more if needed
            size++;



        }
    };

    int extractMin() {
        // checks if empty heap
        if (size == 0) {

            return -1;
        }

        // taking smallest
        int min = heapArray[0];

        // get the last and put in front because you took the smallest one (trying to maintain structure)
        int lastVertex = heapArray[size - 1];
        heapArray[0] = lastVertex;


        // doing same thing now with position array
        position[min] = size - 1;
        position[lastVertex] = 0;
        size--;

        // have to look through heap again because putting last at top (might not keep structure if did this so have to upkeep)
        minHeapify(0);

        // returns what was taken out
        return min;

    }

    // maintaining heap structure (updating in minheap)
    void decreaseKey(int vertex, int newKey) {
        int idx = position[vertex];

        keyArray[vertex] = newKey;

        // checks if smaller than parent
        // if smaller than parent then swap
        while (idx > 0 && keyArray[heapArray[idx]] < keyArray[heapArray[(idx-1) / 2]]) {
            std::swap(heapArray[idx], heapArray[(idx-1) / 2]);
            // update where vertexes are since swap occured
            position[heapArray[idx]] = idx;
            position[heapArray[(idx-1) / 2]] = (idx-1)/2;
            idx = (idx-1)/2;
        }


    }
    // checks if vertex is in heap array by checking whole array
    bool isInMinHeap(int vertex) {
       for (int i = 0; i < size; i++) {
           if (heapArray[i] == vertex) {
               return true;

           }

       }
        return false;
    };

    bool isEmpty() {
        if (size == 0) {

            return true;
        }
        else {
            return false;
        }

    };

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    // still need to finish
    void minHeapify(int idx) {

        // make index smallest or the root
        int root = idx;

        // used to calculate left child of the root ex) root = 0 left child = 2*0+1 = 1
        int leftchild = 2 * idx + 1;

        // used to calculate the right child of the root ex) root = 0 right child = 2 * 0 + 2 = 2 and counts from left to right

        int rightchild = 2 * idx + 2;

        // less than size = in heap and if less than root than it has to be smallest menaing you have to switch
        if (leftchild < size && keyArray[heapArray[leftchild]] < keyArray[heapArray[root]]) {
            root = leftchild;
        }


        // now checks if less than size and if less than root than you have to switch them to keep min heap
        if (rightchild < size && keyArray[heapArray[rightchild]] < keyArray[root]) {
            root = rightchild;
        }

        if (root != idx) {
            // swap if root is not the smallest
            std::swap(heapArray[idx], heapArray[root]);

            // change position arrau to match if root is not the smallest and have to change
            position[heapArray[idx]] = idx;
            position[heapArray[root]] = root;

            // recursion
            minHeapify(root);




        }



    }
};

#endif