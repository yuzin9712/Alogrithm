#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, k;
    vector <int> arr;
    queue <int> q;

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        int size = q.size();
        for(int i = 1; i <= k; i++) {
            if(i == k) {
                arr.push_back(q.front());
                q.pop();
            } else {
                int x = q.front();
                q.pop();
                q.push(x);
            }
        }
        
    }

    cout << "<";

    for(int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << ", ";
    }

    cout << arr[arr.size()-1]<< ">";

    
}