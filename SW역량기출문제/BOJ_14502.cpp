#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int moves[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
int graph[10][10];
int copygraph[10][10];
bool visited[10][10];
int n, m, value, answer, num;
queue<pair<int, int>> q;
vector<pair<int, int>> arr;

void input() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 0) {
                arr.push_back(make_pair(i, j));
                num++;
            }
        }
    }
}

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 2) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }
}

void BFS() {
    int cnt = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && copygraph[nx][ny] != 1 && !visited[nx][ny]) {
                copygraph[nx][ny] = 2;
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(copygraph[i][j] == 0)
                cnt++;
        }
    }

    if(answer < cnt)
        answer = cnt;

}

void wall() {
    vector<bool> temp(num);

    for(int i = 0; i < 3; i++) {
        temp[i] = true;
    }

    sort(temp.begin(), temp.end());


    do
    {
        memcpy(copygraph, graph, sizeof(graph));

        for(int i = 0; i < num; i++) {
            if(temp[i]) {
                // cout << "( " << arr[i].first << ", " << arr[i].second << ")" << " ";
                copygraph[arr[i].first][arr[i].second] = 1;
            }
        }

        init();
        BFS();

        memset(visited, 0, sizeof(visited));

    } while (next_permutation(temp.begin(), temp.end()));
    

}

int main() {

    input();
    wall();
    cout << answer;

}