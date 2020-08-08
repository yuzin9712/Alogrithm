#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[110][110], visited[110];
queue<int> q;
int num, conn, x, y, answer;

void BFS(int v) {
    q.push(v);
    visited[v] = 1;

    while(!q.empty()) {
        v = q.front();
        // cout << q.front() << "\n";
        q.pop();
        answer++;

        for(int i = 1; i <= num; i++) {
            if(graph[v][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    cin >> num >> conn;

    for(int i = 0; i < conn; i++) {
        cin >> x >> y;

        graph[x][y] = 1;
        graph[y][x] = 1;

    }

    BFS(1);

    cout << answer - 1;
}