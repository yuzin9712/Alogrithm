#include <iostream>
#include <queue>
#include <math.h>
#include <cstring>
using namespace std;

int moves[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};
int graph[65][65];
bool visited[65][65];
int N, L, R;

void input() {
    cin >> N >> L >> R;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
}

bool BFS(int x, int y) {
    int cnt = 0;
    int sum = graph[x][y];
    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    q.push({x, y});
    q2.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == 0) {
                if(abs(graph[x][y] - graph[nx][ny]) >= L && abs(graph[x][y] - graph[nx][ny]) <= R) {
                    q.push({nx, ny});
                    q2.push({nx, ny});
                    sum += graph[nx][ny];
                    visited[nx][ny] = true;
                    cnt++;
                }
            }
        }
    }
    
    if(cnt == 0) {
        return false;
    } else {

        int val = sum / (cnt + 1);

        while(!q2.empty()) {
            int x = q2.front().first;
            int y = q2.front().second;

            graph[x][y] = val;
            q2.pop();
        }
        return true;
    }

}

int main() {
    input();
    int answer = 0;

    while(1) {
        answer++;
        bool type = false;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[i][j]) {
                    bool result = BFS(i, j);

                    if(result) {
                        type = true;
                    }
                }
            }
        }


        if(!type) {
            break;
        }
        
        memset(visited, false, sizeof(visited));
    }

    cout << answer - 1;

}