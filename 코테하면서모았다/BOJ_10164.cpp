/*경유지를 거쳐서 가는 모든 경우의 수를 구하기*/
/*DP + DFS로도 풀던데,,*/
#include <iostream>
#include <utility>
#include <stack>
using namespace std;

/*경로를 구하기 위해 스택을 사용한다. -> 역순이 경로임*/
stack<pair<int, int>> s;
int n, m, k;
bool visited[20][20];
int dp[20][20];
int moves[2][2] = {
    {0, 1},
    {1, 0}
};
int num[2];

void DFS(pair<int, int> start, pair<int, int> end, int index) {
    int x = start.first;
    int y = start.second;

    visited[x][y] = true;
    s.push({x, y});

    if(start == end) {
        num[index]++;

        s.pop();
        return ;
    }

    for(int i = 0; i < 2; i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if(!visited[nx][ny]) {
                DFS({nx, ny}, end, index);
                visited[nx][ny] = false;
            }
        }
    }

    s.pop();
}

void input() {
    cin >> n >> m >> k;
}

int solution() {
    int answer = 0;

    if(k == 0) {
        DFS({0, 0}, {n - 1, m - 1}, 0);
        answer = num[0];
    } else {
        int stopX, stopY;

        stopX = (k - 1) / m;
        stopY = (k - 1) % m;

        DFS({0, 0}, {stopX, stopY}, 0);
        DFS({stopX, stopY}, {n - 1, m - 1}, 1);
        answer = num[0] * num[1];
    }

    return answer;
}

int main() {

    input();
    cout << solution();

}