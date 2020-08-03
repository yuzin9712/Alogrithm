#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

bool graph[110][110];
int check[110][110];
int moves[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
int n, m;
queue<pair<int, int>> q;

void BFS(int x, int y) {
    check[x][y] = 1;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == n && y == m) {
            break;
        }
 
        for(int j = 0; j < 4; j++) {
            int newx = x + moves[j][0];
            int newy = y + moves[j][1];

            if(graph[newx][newy] == 1 && check[newx][newy] == 0) {
                check[newx][newy] = check[x][y] + 1;
                q.push(make_pair(newx, newy));
            }
        }
        
    }

}

int main() {
    
    char c;

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c;
            graph[i][j] = c - '0';
        }
    }

    BFS(1,1);

    cout << check[n][m];

}