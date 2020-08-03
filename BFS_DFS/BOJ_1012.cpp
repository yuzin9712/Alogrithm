#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int visited[65][65];
int graph[65][65];
int moves[4][4] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
int t, m, n, k;

void BFS(int x, int y) {
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // cout << "(" << x << ", " << y << ")\n";

        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && graph[nx][ny] == 1) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
}

// void DFS(int x, int y) {
//     visited[x][y] = 1;

//     for(int i = 0; i < 4; i++) {
//         int nx = x + moves[i][0];
//         int ny = y + moves[i][1];

//         if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[x][y] == 0 && graph[x][y] = 1) {

//         }
//     }
// }

int main() {
    cin >> t;

    for(int l = 0; l < t; l++) {
        cin >> m >> n >> k;
        int x, y, answer = 0;

        for(int i = 0; i < k; i++) {
            cin >> y >> x;
            graph[x][y] = 1;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == 0 && graph[i][j] == 1) {
                    BFS(i, j);
                    answer++;
                }
            }
        }

        cout << answer << "\n";
        
        /*초기화해줄때사용*/
        memset(visited,0, sizeof(visited));
        memset(graph,0, sizeof(graph));
    }
}