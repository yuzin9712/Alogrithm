#include <iostream>
using namespace std;

int dp[100010][3], n;

int main() {
    cin >> n;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp [i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
    }

    /*두 군데에서 모두 9901로 나누어야 함 오버플로우 발생으로 인해 ?*/
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
}