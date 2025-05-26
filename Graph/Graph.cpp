#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

Graph::Graph(int vertices) : size(vertices), adjMatrix(vertices, vector<int>(vertices, 0)) {}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::removeEdge(int u, int v) {
    adjMatrix[u][v] = 0;
    adjMatrix[v][u] = 0;
}

void Graph::setWeight(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::addVertex() {
    size++;
    for (auto& row : adjMatrix) {
        row.push_back(0);
    }
    adjMatrix.push_back(vector<int>(size, 0));
}

void Graph::removeVertex(int v) {
    adjMatrix.erase(adjMatrix.begin() + v);
    for (auto& row : adjMatrix) {
        row.erase(row.begin() + v);
    }
    size--;
}

void Graph::bfs(int start) {
    vector<bool> visited(size, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS from " << start + 1 << ": ";
    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v + 1 << " ";

        for (int i = 0; i < size; ++i) {
            if (adjMatrix[v][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void Graph::dfs(int start) {
    vector<bool> visited(size, false);
    stack<int> st;
    st.push(start);

    cout << "DFS from " << start + 1 << ": ";
    while (!st.empty()) {
        int v = st.top(); st.pop();
        if (!visited[v]) {
            visited[v] = true;
            cout << v + 1 << " ";

            for (int i = size - 1; i >= 0; --i) {
                if (adjMatrix[v][i] && !visited[i]) {
                    st.push(i);
                }
            }
        }
    }
    cout << endl;
}

void Graph::dijkstra(int start) {
    vector<int> dist(size, INF);
    vector<bool> visited(size, false);
    vector<int> prev(size, -1);
    dist[start] = 0;

    for (int i = 0; i < size; ++i) {
        int v = -1;
        for (int j = 0; j < size; ++j)
            if (!visited[j] && (v == -1 || dist[j] < dist[v])) v = j;

        if (dist[v] == INF) break;
        visited[v] = true;

        for (int j = 0; j < size; ++j) {
            if (adjMatrix[v][j] && dist[v] + adjMatrix[v][j] < dist[j]) {
                dist[j] = dist[v] + adjMatrix[v][j];
                prev[j] = v;
            }
        }
    }

    cout << "Dijkstra from " << start + 1 << ":\n";
    for (int i = 0; i < size; ++i) {
        if (dist[i] == INF) {
            cout << i + 1 << ": No path\n";
            continue;
        }
        cout << "To " << i + 1 << ": dist = " << dist[i] << " | Path: ";
        vector<int> path;
        for (int v = i; v != -1; v = prev[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        for (int v : path) cout << v + 1 << " ";
        cout << endl;
    }
}

const vector<vector<int>>& Graph::getMatrix() const {
    return adjMatrix;
}
