#include <iostream>
#include "graph.h"

int main() {

    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();






    /* trial
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);
    */

    /*
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
   */

    return 0;
}