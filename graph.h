#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

class Graph {
public:

    Graph(int vertices) { // constructor for making the 2d adjacency matrix
        numVertices = vertices;

        adjMatrix = new int *[numVertices]; // memory for matrix
        for (int i = 0; i < numVertices; i++) {
            // rows
            adjMatrix[i] = new int[numVertices];
        }
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                // this makes it so that the diagonal is all zeros which it is for a diagonal matrix
                if (i == j) {
                    adjMatrix[i][j] = 0;
                } else {
                    adjMatrix[i][j] = INT_MAX; // makes everything infinity at first because there is no edges between points
                }


            }
        }
    }
    ~Graph() { // destructor
        // deletes all rows and columns so no error (I HATE SEGMENTATION ERRORS)
       for (int i = 0; i < numVertices; i++) {
           delete[] adjMatrix[i];
       }
        delete[] adjMatrix;


    }
    // makes an edge between U and V with a weight but makes it both ways since prim goes both ways (undirected)
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void printGraph() { // prints eveyrthing in graph that was created already
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] == INT_MAX)
                    // if infinity make infinity sign instead of just value of int max
                    std::cout << "∞ ";

                // if not infinity just print actual value
                else {
                    std::cout << adjMatrix[i][j] << " ";
                }
            }
            // to print horizontaly
            std::cout << std::endl;

        }

    }

    void primMST() {

        std::cout << "Given this adjacent matrix" << std::endl;
        // just trying to see if array will print (printed on one row try new print graph)
        // got done prints the matrix before prims is applied to it
        printGraph();
        std::cout << "after applying prims algorithim... " << std::endl;


        // array that shows what vertex another vertex is connected to (changed to vector so no deleting needed)
        std::vector<int> parent(numVertices);

        // array that holds the minimum distance to connect (changed to vector)
        std::vector<int> MinDistance(numVertices);;

        // makes heap https://www.youtube.com/watch?v=XWEEmITavdc (used for making structure but tweaked it so it uses the three arrays we were given)
        MinHeap minheap(numVertices);
        for (int i = 0; i < numVertices; i++) {
            parent[i] = -1;
            MinDistance[i] = INT_MAX;
            minheap.insert(i, MinDistance[i]);

        }
        // picks 0 first
        MinDistance[0] = 0;
        minheap.decreaseKey(0, MinDistance[0]);


        while (!minheap.isEmpty()) {
            // while the minheap is empty get the minimum
            int v = minheap.extractMin();
            // checks neighbor
            for (int i = 0; i < numVertices; i++) {
                // if there is a connection (not int max) is in the minheap and is less than minimum distance, update since better way found
                if (adjMatrix[v][i] != INT_MAX && minheap.isInMinHeap(i) && adjMatrix[v][i] < MinDistance[i]) {
                    MinDistance[i] = adjMatrix[v][i];
                    parent[i] = v;
                    minheap.decreaseKey(i, MinDistance[i]);
                }
            }

        }
        int weight = 0;
        // shows all best connections for each point given then print total weight
        for (int i = 1; i < numVertices; i++) {
            if (parent[i] != -1) {
                std::cout << parent[i] << " <----> " << i << "   Cost = " << adjMatrix[i][parent[i]] << std::endl;
                weight += adjMatrix[i][parent[i]];
            }

        }
        std::cout << "Lowest Cost Path to get all vertices is " << weight << std::endl;

    }
    // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif