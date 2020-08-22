#include <iostream>
using namespace std;

int dp[2][10], n, answer = 0;

int main() {

    cin >> n;

    for(int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0)  dp[i % 2][j] = dp[(i - 1) % 2][1] % 1000000000;
            else if(j == 9)  dp[i % 2][j] = dp[(i - 1) % 2][8] % 1000000000;
            else        dp[i % 2][j] = (dp[(i - 1) % 2][j - 1] + dp[(i - 1) % 2][j + 1]) % 1000000000;
        }
    }

    for(int i = 0; i < 10; i++) {
        answer = (answer + dp[n % 2][i]) % 1000000000;
    }

    cout << answer;


}