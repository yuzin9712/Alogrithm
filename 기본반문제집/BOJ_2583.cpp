#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int m, n, k, answer, index;
bool graph[110][110], visited[110][110];
vector<int> arr(1010);
int moves[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
queue<pair<int, int>> q;

void BFS(int x, int y) {
    
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    arr[index]++;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == 0 && graph[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
                arr[index]++;
            }
        }
    }
}

int main() {
    cin >> m >> n >> k;
    int sx, sy, ex, ey;

    for(int i = 0; i < k; i++) {
        cin >> sx >> sy >> ex >> ey;

        /*이 부분 잘 모르겠음 ㅡㅡ*/
        for(int x = sx; x < ex; x++) {
            for(int y = sy; y < ey; y++) {
                graph[y][x] = 1;
            }
        }
    }

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] == 0 && visited[i][j] == 0) {
                BFS(i, j);
                answer++;
                index++;
            }
        }
    }

    cout << answer << "\n";

    sort(arr.begin(), arr.begin() + answer);

    for(int i = 0; i < answer; i++) {
        cout << arr[i] << " ";
    }
}