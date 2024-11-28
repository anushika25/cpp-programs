#include <iostream>
using namespace std;

bool linearSearch(int graph[][5], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == target) return true;
        }
    }
    return false;
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
    int target = 1;
    cout << (linearSearch(graph, n, target) ? "Found" : "Not Found") << endl;
    return 0;
}