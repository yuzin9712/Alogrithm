#include <iostream>
#include <cstring>
using namespace std;

int moves[2][2] = {
    {0, 1}, /*가로*/
    {1, 0} /*세로*/
};
int graph[110][110], visited[110][110];
int n;
int row, column; /*행 열*/ 
int cnt;

void DFS_r(int x, int y) {
    visited[x][y] = 1;
    cnt++;
    // cout << "(" << x << ", " << y << ") cnt : " << cnt << "\n";
    
    int nx = x + moves[0][0];
    int ny = y + moves[0][1];

    if(nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0 && graph[nx][ny] == 0) {
        visited[nx][ny] = 1;
        DFS_r(nx, ny);
    }
}

void DFS_c(int x, int y) {
    visited[x][y] = 1;
    cnt++;
    // cout << "(" << x << ", " << y << ") cnt : " << cnt << "\n";
    
    int nx = x + moves[1][0];
    int ny = y + moves[1][1];

    if(nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0 && graph[nx][ny] == 0) {
        visited[nx][ny] = 1;
        DFS_c(nx, ny);
    }
}

int main() {
    char c;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c;
            if(c == '.') graph[i][j] = 0;
            if(c == 'X') graph[i][j] = 1; /*벽*/
        }
    }

    for(int i = 0; i < n; i++) {
        cnt = 0;
        for(int j = 0; j < n; j++) {
            if(graph[i][j] == 0 && visited[i][j] == 0) {
                // cout << "new call dfs\n" << "\n";
                DFS_r(i, j);
                if(cnt >= 2) {
                row++;
                // cout << "row is " << row << "\n";
                }
            }
            if(graph[i][j] == 1) {
                cnt = 0;
            }
        }
    }

    cout << row << " ";

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++) {
        cnt = 0;
        for(int j = 0; j < n; j++) {/*행*/
            if(graph[j][i] == 0 && visited[j][i] == 0) {
                DFS_c(j, i);
                if(cnt >= 2) {
                column++;
                // cout << "column is " << column << "\n";
                }
            }

            if(graph[j][i] == 1) {
                cnt = 0;
            }
        }
    }
    
    cout << column;
    
}