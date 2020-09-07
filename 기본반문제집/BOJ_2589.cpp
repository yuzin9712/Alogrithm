#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, timegraph[65][65], MAX;
char graph[65][65];
bool visited[65][65];
int moves[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

void BFS(int x, int y) {
    queue<pair<int, int>> q;

    visited[x][y] = true;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] == 'L' && !visited[nx][ny]) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                timegraph[nx][ny] = timegraph[x][y] + 1;
                if(MAX < timegraph[nx][ny])
                    MAX = timegraph[nx][ny];
            }
        }
    }

    
}

int main() {
    char c;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c;
            graph[i][j] = c;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 'L')
                BFS(i, j);
            
            memset(visited, false, sizeof(visited));
            memset(timegraph, 0, sizeof(timegraph));
        }
    }

    cout << MAX;

    
}