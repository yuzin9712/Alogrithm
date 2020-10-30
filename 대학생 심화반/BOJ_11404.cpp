#include <iostream>
#include <vector>
#define INF 1000000001
using namespace std;

int **graph;
int n, m;

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
}

void input() {
    int x, y, cost;

    cin >> n >> m;

    graph = (int **)malloc(sizeof(int*) * n);

    for(int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(sizeof(int) * n);
    }

    init();

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> cost;

        if(graph[x - 1][y - 1] > cost) {
            graph[x - 1][y - 1] = cost;
        }
    }
}

void FloydWashall() {
    for(int middle = 0; middle < n; middle++) {
        for(int start = 0; start < n; start++) {
            for(int end = 0; end < n; end++) {
                if(graph[start][end] > graph[start][middle] + graph[middle][end]) {
                    graph[start][end] = graph[start][middle] + graph[middle][end];
                }
            }
        }
    }
}

int main() {
    input();
    FloydWashall();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] == INF) {
                graph[i][j] = 0;
            }
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}