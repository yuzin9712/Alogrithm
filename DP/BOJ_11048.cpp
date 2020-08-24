/*
왜 bfs 가 아니라 dp 일까?
bfs 는 가중치가 모두 1 인 경우 최소 이동거리 를 구할 때 사용
하지만 이 문제에서는 이동거리는 상관 없고 얻어지는 사탕의 수가 최대 값이 되어야함
따라서 bfs로 푸는 것이 아니다. 
*/
#include <iostream>
#define MAX(a, b) a > b ? a : b
using namespace std;

int dp[1010][1010], graph[1010][1010], n, m, input;

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> input;
            graph[i][j] = input;
        }
    }

    dp[1][1] = graph[1][1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1)  dp[i][j] = graph[i][j] + dp[i][j - 1];
            else if(j == 1)  dp[i][j] = graph[i][j] + dp[i - 1][j];
            else    dp[i][j] = MAX(graph[i][j] + dp[i - 1][j], graph[i][j] + dp[i][j - 1]);
        }
    }

    cout << dp[n][m];
}