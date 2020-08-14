#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n, input;
    long long sum = 0;
    priority_queue<int> ppq;
    priority_queue<int, vector<int>, greater<int>> mpq;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> input;

        if(input > 0)   ppq.push(input);
        else            mpq.push(input);

    }

    while(!ppq.empty()) {
        
        if(ppq.size() < 2) {
            sum += ppq.top();
            ppq.pop();
        } else {
            long long x = ppq.top();
            ppq.pop();
            long long y = ppq.top();
            ppq.pop();

            (x + y > x * y) ? (sum += x + y) : (sum += (x * y));
        }
    }

    // cout << sum;


    while(!mpq.empty()) {
        if(mpq.size() < 2) {
            sum += mpq.top();
            mpq.pop();
        } else {
            long long x = mpq.top();
            mpq.pop();
            long long y = mpq.top();
            mpq.pop();

            sum += (x * y);
        }
    }

    cout << sum;

    
}