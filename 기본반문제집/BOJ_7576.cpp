/*다시 풀어봐야함!!!!!!!!!!!!!!!!!!!!*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int graph[1010][1010], visited[1010][1010];
queue<pair<int, int>> q;
int m, n, answer;
int moves[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int BFS() {
    int days = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // cout << "(" << x << ", " << y << ")\n";

        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && graph[nx][ny] == 0) {
                visited[nx][ny] = 1;
                graph[nx][ny] = graph[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    return days;
}


int main() {
    int c;

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c; 
            graph[i][j] = c;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 1 && visited[i][j] == 0) {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }

    BFS();

    int answer = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            if(graph[i][j] == 0) {
                answer = -1;
                cout << answer;
                return 0;
            }

            if(answer < graph[i][j]) {
                answer = graph[i][j] - 1;
            }
        }
    }

    cout << answer;

   
}