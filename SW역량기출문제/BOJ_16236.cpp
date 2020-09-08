#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int graph[35][35];
int n, answer;
/* 상어 관련 */
int sx, sy, ssize = 2, scnt;
bool visited[35][35];
int moves[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1} 
};

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if(a.first == b.first) {
        if (a.second.first == b.second.first) {
            return (a.second.second < b.second.second) ? true : false;
        }
        return (a.second.first < b.second.first) ? true : false;
    }

    return (a.first < b.first) ? true : false;
}

vector<pair<int, pair<int, int>>> BFS(int x, int y) {
    int copygraph[35][35] = {0, };
    vector<pair<int, pair<int, int>>> arr;
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    graph[x][y] = 0;
    visited[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && graph[nx][ny] <= ssize) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                copygraph[nx][ny] = copygraph[x][y] + 1;

                if(graph[nx][ny] != 0 && graph[nx][ny] < ssize) {
                    arr.push_back(make_pair(copygraph[nx][ny], make_pair(nx, ny)));
                }
            } 
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << copygraph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    sort(arr.begin(), arr.end(), comp);

    // for(int i = 0; i < arr.size(); i++) {
    //     cout << arr[i].first << " (" << arr[i].second.first << ", " << arr[i].second.second << ")\n";
    // }

    return arr;
}


void input() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 9) {
                sx = i;
                sy = j;
                graph[i][j] = 0;
            }
        }
    }
}

int main() {

    vector<pair<int, pair<int, int>>> arr;

    input();

    while(1) {
        
        if(scnt == ssize) {
            scnt = 0;
            ssize++;
        }

        arr = BFS(sx, sy);

        if(arr.size() == 0) { 
            break;
        }

        scnt++;

        // cout << "answer : " << answer << " size :" << ssize << "\n";
        
        sx = arr[0].second.first;
        sy = arr[0].second.second;

        answer += arr[0].first;
        
        memset(visited, false, sizeof(visited));
        
    }

    cout << answer;
    
}