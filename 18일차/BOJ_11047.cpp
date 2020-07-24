#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> value;

    int n, k, answer = 0;
    int x;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> x;
        value.push_back(x);
    }

    for(int i = n-1; i >= 0; i--) {
        if(k != 0 && value[i] <= k) {
            answer = answer + k / value[i];
            k = k % value[i];
        }
    }

    cout << answer;

    
}