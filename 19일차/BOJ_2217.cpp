#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    int n, w, max = 0;
    vector <int> ropes;

    cin >> n;

    for(int i = 0; i < n; i++) {

        cin >> w;
        ropes.push_back(w);
        
    }

    sort(ropes.begin(), ropes.end());

    for(int j = ropes.size() - 1; j >= 0; j--) {
        
        if(ropes[j] * (ropes.size() - j) > max) {
            max = ropes[j] * (ropes.size() - j);
        }
    }

    cout << max;
    

}