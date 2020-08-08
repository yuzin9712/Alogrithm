#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int visited[310][310];
int moves[8][2] = {
    {-2, -1}, 
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1}
};
int t, l, cx, cy, ax, ay;

void BFS(int x, int y) {
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(x == ax && y == ay) {
            break;
        }

        for(int i = 0; i < 8; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(nx >= 0 && nx < l && ny >= 0 && ny < l && visited[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
}

int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> l >> cx >> cy >> ax >> ay;

        BFS(cx, cy);

        // for(int j = 0; j < l; j++) {
        //     for(int k = 0; k < l; k++) {
        //         cout << visited[j][k] << " ";
        //     }
        //     cout << "\n";
        // }

        cout << visited[ax][ay] - 1 << "\n";

        memset(visited, 0, sizeof(visited));
    }

}

/*
왜 dfs 로는 안 풀리는가?

- 깊이 우선 탐색으로 경로 검색해서 원하는 위치에 도달했을 때
그 답이 최단 거리가 아닐 수 있음!!!

하지만 너비 우선 탐색의 경우 현재 위치에서 가까운 곳부터 찾기 때문에 최단 거리가 성립됨@_@
*/