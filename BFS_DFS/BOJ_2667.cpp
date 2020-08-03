#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int moves[4][2] ={
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
bool visited[26][26], graph[26][26];
vector<int> ans(626);
int n, num;

void DFS(int x, int y, int num) {
    visited[x][y] = 1;
    graph[x][y] = num;
    ans[num]++;
    // cout << "(" << x << ", " << y << ") num : " << num << "\n";
 
    for(int i = 0; i < 4; i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];

        if(nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0 && graph[nx][ny] == 1) {
            DFS(nx, ny, num);
        }
    }
}

int main() {
    char c;
    int answer = 0;
    num = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) {
            cin >> c;
            graph[i][j] = c - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 0 && graph[i][j] == 1) {
                num++;
                DFS(i, j, num);
                answer++;
            }
        }
    }

    cout << answer << "\n";

    sort(ans.begin() + 1, ans.begin() + 1 + num);

    for(int i = 1; i <= num; i++) {
        cout << ans[i] << "\n";
    }

}