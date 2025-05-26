#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

const int INF = 1e9;

class Graph
{
private:
    int size;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices = 6);
    void addEdge(int u, int v, int weight);
    void removeEdge(int u, int v);
    void setWeight(int u, int v, int weight);
    void addVertex();
    void removeVertex(int v);

    void bfs(int start);
    void dfs(int start);
    void dijkstra(int start);

    const std::vector<std::vector<int>>& getMatrix() const;
};

#endif
