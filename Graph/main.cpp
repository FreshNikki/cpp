#include "Graph.h"
#include "Visualizer.h"
#include <GLUT/glut.h>

int main(int argc, char** argv)
{
    Graph graph(6);

    graph.addEdge(0, 1, 8);
    graph.addEdge(0, 5,11);
    graph.addEdge(1, 2,12);
    graph.addEdge(1, 4,10);
    graph.addEdge(2, 3,16);
    graph.addEdge(3, 4, 5);
    graph.addEdge(3, 5, 9);
    graph.addEdge(4, 5, 6);

    graph.bfs(5);      
    graph.dfs(5);
    graph.dijkstra(5);

    initOpenGL();
    extern Graph* graphPtr;
    graphPtr = &graph;
    glutMainLoop();

    return 0;
}
