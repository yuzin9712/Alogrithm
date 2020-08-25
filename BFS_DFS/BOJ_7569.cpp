#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m, n, h, t, answer;
int graph[110][110][110], visited[110][110][110];
int moves[6][3] = {
    {-1, 0, 0},
    {1, 0, 0},
    {0, -1, 0},
    {0, 1, 0},
    {0, 0, 1},
    {0, 0, -1}
};
queue<tuple<int, int, int>> q;

void input() {
    cin >> m >> n >> h;

    for(int z = 1; z <= h; z++) {
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                cin >> t;

                if(t == 1) {
                    q.push(make_tuple(x, y, z));
                    visited[x][y][z] = 1;
                }

                graph[x][y][z] = t;
            }
        }
    }
}

void BFS() {

    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());

        q.pop();

        for(int i = 0; i < 6; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];
            int nz = z + moves[i][2];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 1 && nz <= h && !visited[nx][ny][nz] && graph[nx][ny][nz] == 0) {
                q.push(make_tuple(nx, ny, nz));
                visited[nx][ny][nz] = 1;
                graph[nx][ny][nz] = graph[x][y][z] + 1;
            }
        }
    }
}

void output() {

    for(int z = 1; z <= h; z++) {
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                // cout << graph[x][y][z] << " ";
                if(graph[x][y][z] == 0) {
                    cout << -1;
                    return ;
                }
                if(graph[x][y][z] > answer) {
                    answer = graph[x][y][z];
                }
            }
            // cout << "\n";
        }
        // cout << "\n";
    }

    cout << answer - 1;
    return ;
}

int main() {

    input();
    BFS();
    output();

}