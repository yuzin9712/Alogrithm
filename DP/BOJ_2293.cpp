#include <iostream>
#include <vector>
using namespace std;

int n, k, input, answer;
vector<int> value;
int dp[100001];

int main() {

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> input;
        value.push_back(input);
    }

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = value[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - value[i]];
        }
    }

    cout << dp[k];
    
}