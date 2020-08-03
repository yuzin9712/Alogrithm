#include <iostream>
#include <vector>
using namespace std;

bool graph[1015][1015], visited[1015];
int n;

void DFS(int v) {
    visited[v] = 1;

    for(int i = 1; i <= n; i++) {
        if(graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
} 

int main() {
    int answer = 0;
    int m, x, y;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            DFS(i);
            answer++;
        } 
    }
    cout << answer;

    
}