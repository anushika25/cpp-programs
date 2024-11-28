#include <iostream>
using namespace std;

void dfs(int node, int graph[][5], bool visited[], int n) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, graph, visited, n);
        }
    }
}

int main() {
    int n = 5;
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    bool visited[5] = {false};
    dfs(0, graph, visited, n);
    return 0;
}