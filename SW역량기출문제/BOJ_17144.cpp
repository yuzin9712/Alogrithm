#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int r, c, t;
int position[2];
int graph[65][65];
int moves[4][2] = {
    {1, 0},
    {0, -1},
    {-1, 0},
    {0, 1}
}; 
/*
아 - 왼 - 위 - 오

ccw : 3 2 1 0
cw : 3 0 1 2
*/
int ccw[4] = {3, 2, 1, 0};
int cw[4] = {3, 0, 1, 2};
int answer;

bool visited[65][65];
queue<pair<int, pair<int, int>>> q;

void diffusion() {

    while(!q.empty()) {
        int cnt = 0;
        int value = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(nx >= 0 && nx < r && ny >= 0 && ny < c && graph[nx][ny] != -1) {
                cnt++;
                graph[nx][ny] += (value / 5);
            }
        }

        graph[x][y] -= ((value / 5) * cnt);
    }
}

void circulate(int x1, int x2) {
    /*반시계 방향*/

    int copygraph[65][65];
    memcpy(copygraph, graph, sizeof(graph));

    int y = 0;

    for(int i = 0; i < 4; i++) {
        while(true) {
            int nx = x1 + moves[ccw[i]][0];
            int ny = y + moves[ccw[i]][1];

            if(nx >= 0 && nx < r && ny >= 0 && ny < c && graph[nx][ny] != -1) {
                if(graph[x1][y] == -1) {
                    graph[nx][ny] = 0;
                } else {
                    graph[nx][ny] = copygraph[x1][y];
                }
            } else {
                break;
            }

            x1 = nx;
            y = ny;
        }
    }

    // cout << "\n\nccw\n\n";

    // for(int i = 0; i < r; i++) {
    //     for(int j = 0; j < c; j++) {
    //         cout << copygraph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    /*시계 방향*/
    y = 0;

    for(int i = 0; i < 4; i++) {
        while(true) {
            int nx = x2 + moves[cw[i]][0];
            int ny = y + moves[cw[i]][1];

            if(nx >= 0 && nx < r && ny >= 0 && ny < c && graph[nx][ny] != -1) {
                if(graph[x2][y] == -1) {
                    graph[nx][ny] = 0;
                } else {
                    graph[nx][ny] = copygraph[x2][y];
                }
            } else {
                break;
            }

            x2 = nx;
            y = ny;
        }
    }
}

void solution() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(graph[i][j] >= 5) {
                q.push(make_pair(graph[i][j],make_pair(i, j)));
            }
        }
    }

    diffusion();

    // for(int i = 0; i < r; i++) {
    //     for(int j = 0; j < c; j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    circulate(position[0], position[1]);


    
}

void input() {
    int k = 0;
    cin >> r >> c >> t;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == -1){
                position[k] = i;
                k++;
            }
        }
    }
}

int main() {

    input();

    for(int i = 0; i < t; i++) {
        solution();
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(graph[i][j] != -1)
                answer += graph[i][j];
        }
    }

    cout << answer;

}