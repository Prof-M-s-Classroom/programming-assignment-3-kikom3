[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
David Soriano

## Description
What the program does is given vertices and edges between them, it utilizes prim's algorithim to be able to find the shortest path that hits all the verticies while also being able to get the lowest cost


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

Insert in MinHeap has O(logn) runtime because of the fact that it uses minheapify which will keep comparing recursively to keep the minheap property, with the comparisons being halfed compared to the number of elements inside the tree itself

Extract Min has O(logn) runtime also because of the minheapify function being called into the function, as taking out the minimum from the minheap could lead to the minheap properties not being sustained after swaps happen

Decrease Key ends up being logn since at worst the newest key put in the heap would be the smallest which would make it have to go up the whole tree, which would end up being logn height, meaning its big o runtime would be logn

My Prim Mst Overall is n^2 because it has to iterate over a 2d matrix chekcing the neighbors of each vertex to see what the lowest cost path would be next.


## Test Case Description
hand did as practice for prim's checked and got same edge values and overall weight which makes sense since all those is supposed to come out the same



Input:

    // original
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    g.primMST();

    // trial
    
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 5, 6);
    g.addEdge(3, 4, 5);
    g.addEdge(4, 5, 7);
    g.primMST();
    
    
    
    // trial
    Graph g(7);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 6);
    g.addEdge(2, 4, 5);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 7);
    g.addEdge(3, 6, 8);
    g.addEdge(4, 5, 2);
    g.addEdge(5, 6, 1);
    g.primMST();

    // notes of doing test cases
    https://share.goodnotes.com/s/jMqgNiRky2ngSpygc78P6U