#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, height, answer = 0;
int graph[110][110];
int moves[4][2] = {
    {1, 0}, 
    {0, 1},
    {-1, 0},
    {0, -1}
};
bool visited[110][110];
queue<pair<int, int>> q;

void BFS(int x, int y, int k) {

    q.push(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n && graph[nx][ny] > k && !visited[nx][ny]) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

}

int input() {
    int value = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> height;
            if(value < height)
                value = height;
            graph[i][j] = height;
        }
    }

    return value;

}

int main() {
    int temp, max;

    max = input();

    for(int k = 0; k < max; k++) {
        temp = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] > k && !visited[i][j]) {
                    BFS(i, j, k);
                    temp++;
                }
            }
        }
        
        if(temp > answer)
            answer = temp;

        memset(visited, 0, sizeof(visited));
    }

    cout << answer;
}