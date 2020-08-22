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