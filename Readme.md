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
hand did as practice for prim's checked and got same edge values and overall weight which makes sense since all those is supposed to come out the same



Input:  
Graph g(6);
g.addEdge(0, 1, 4);
g.addEdge(0, 2, 3);
g.addEdge(1, 2, 1);
g.addEdge(1, 3, 2);
g.addEdge(2, 5, 6);
g.addEdge(3, 4, 5);
g.addEdge(4, 5, 7);
g.primMST();