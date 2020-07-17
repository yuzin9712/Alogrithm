#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    queue <int> q;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    while(q.size() != 1) {
        q.pop();
        int x = q.front();
        q.pop();
        q.push(x);
    }

    cout << q.front();
}