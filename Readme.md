[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
David Soriano

## Description
What the program does is given vertices and edges between them, it utilizes prim's algorithim to be able to find the shortest path that hits all the verticies while also being able to get the lowest cost
Briefly describe what your program does and how the code is structured.

## Files
- graph.h 
- heap.h 
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log n)        |
| Extract Min          | O(log n)        |
| Decrease Key         | O(log n)        |
| Prim’s MST Overall   | O(n^2)          |

_Explain why your MST implementation has the above runtime._

## Test Case Description
Graph g(5)



Input:  