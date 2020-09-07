#include <iostream>
#include <queue>
using namespace std;

int r, c, answer;
char alphabet;
char graph[35][35];
bool visited[30];
int moves[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

void input() {
    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> alphabet;
            graph[i][j] = alphabet;
        }
    }
}

void DFS(int x, int y, int cnt) {

    if(cnt > answer)
        answer = cnt;

    for(int i = 0; i < 4; i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];

        if(nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if(!visited[graph[nx][ny] - 'A']) {
                visited[graph[nx][ny] - 'A'] = true;
                DFS(nx, ny, cnt + 1);
                visited[graph[nx][ny] - 'A'] = false;
            }
        }
    }

}

int main() {
    input();
    visited[graph[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << answer;
}