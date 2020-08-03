#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[1010][1010];
int visited[2][1010];
queue <int> q;
int n, m, v;
int x, y;

void DFS(int v) {
    cout << v << " ";
    visited[0][v] = 1;

    for(int i = 1; i <= n; i++) {
        if(graph[v][i] == 1 && visited[0][i] == 0) {
            DFS(i);
        }
    }

}

void BFS(int v) {
    q.push(v);
    visited[1][v] = 1;

    while(!q.empty()) {
        int newv = q.front();
        cout << newv << " ";
        q.pop();
        

        for(int i = 1; i <= n; i++) {
            if(graph[newv][i] == 1 && visited[1][i] == 0) {
                q.push(i);
                visited[1][i] = 1; 
            }
        }

    }
    
}

int main() {

    cin >> n >> m >> v;

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    DFS(v);
    cout << "\n";
    BFS(v);
}