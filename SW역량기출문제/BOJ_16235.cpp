#include <iostream>
#include <cstdio>
#include <deque>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int nourishments[15][15], addedNourishments[15][15];
deque<int> graph[15][15];
int n, m, k, answer;
bool visited[15][15];
bool newvisited[15][15];
queue<pair<int, pair<int, int>>> alive;
queue<pair<int, pair<int, int>>> dead;
int moves[8][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};

void input() {
    int num, x, y, age;

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &addedNourishments[i][j]);
        }
    }

    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &age);

        graph[x][y].push_back(age);
        
        if(!visited[x][y]) {
            visited[x][y] = true;
            alive.push({age, {x, y}});
        }
    }
}

void init() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            nourishments[i][j] = 5;
        }
    }
}

void spring() {
    queue<pair<int, pair<int, int>>> newalive;

    while(!alive.empty()) {
        
        int x = alive.front().second.first;
        int y = alive.front().second.second;

        alive.pop();

        sort(graph[x][y].begin(), graph[x][y].end());

        for(int i = 0; i < graph[x][y].size(); i++) {
            if(graph[x][y][i] <= nourishments[x][y]) {
                nourishments[x][y] -= graph[x][y][i];
                graph[x][y][i]++;
                if(!newvisited[x][y]) {
                    newalive.push({graph[x][y][i], {x, y}});
                    newvisited[x][y] = true;
                }
            } else {
                int j = graph[x][y].size() - 1;
                while(i <= j) {
                    int age = graph[x][y].back();
                    dead.push({age, {x, y}});
                    graph[x][y].pop_back();
                    j--;
                }
                break;
            }
        }
    }

    alive = newalive;
}

void summer() {
    while(!dead.empty()) {
        int age = dead.front().first;
        int x = dead.front().second.first;
        int y = dead.front().second.second;
        
        dead.pop();

        nourishments[x][y] += (age / 2);   
    }
}

void fall() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < graph[i][j].size(); k++) {
                if(graph[i][j][k] % 5 == 0) {
                    for(int l = 0; l < 8; l++) {
                        int nx = i + moves[l][0];
                        int ny = j + moves[l][1];

                        if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                            graph[nx][ny].push_front(1);
                            if(!newvisited[nx][ny]) {
                                alive.push({1, {nx, ny}});
                                newvisited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void winter() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            nourishments[i][j] += addedNourishments[i][j];
        }
    }
}

void getAnswer() {
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y++) {
        // cout << "(" << x << ", " << y << ") ";
            for(int z = 0; z < graph[x][y].size(); z++) {
                // cout << graph[x][y][z] << " ";
                answer++;
            }
        }
    // cout << "\n";
    }
    printf("%d", answer);
}

void solution() {
    for(int i = 0; i < k; i++) {
        spring();
        summer();
        fall();
        winter();

        memset(visited, 0, sizeof(visited));
        memset(newvisited, 0, sizeof(newvisited));
        
    }
    
    getAnswer();
}

int main() {

    input();
    init();
    solution();

}