#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

char graph[110][110], check[110][110], input;
int moves[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
int n, answer1, answer2;


void BFS(int x, int y, char color, bool type) {
    queue<pair<int, int>> q;
    
    check[x][y] = 1;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(type == 1) {
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && check[nx][ny] == 0 && color == graph[nx][ny]) {
                q.push(make_pair(nx, ny));
                check[nx][ny] = 1;
                }
            } else {
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && check[nx][ny] == 0 && ((color == graph[nx][ny]) || (color == 'R' && graph[nx][ny] == 'G') || (color == 'G' && graph[nx][ny] == 'R'))) {
                q.push(make_pair(nx, ny));
                check[nx][ny] = 1;
                }   
            }
        }
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input;

            graph[i][j] = input;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(check[i][j] == 0) {
                BFS(i, j, graph[i][j], 1);
                answer1++;
            }
        }
    }

    memset(check, 0, sizeof(check));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(check[i][j] == 0) {
                BFS(i, j, graph[i][j], 0);
                answer2++;
            }
        }
    }

    cout << answer1 << " ";
    cout << answer2;
}