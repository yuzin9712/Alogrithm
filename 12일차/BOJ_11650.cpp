#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair <int, int> a, pair <int, int> b);

int main() {
    int n, x, y;
    vector <pair <int, int>> arr;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        arr.push_back(make_pair(x,y));
    }

    sort(arr.begin(), arr.end(), comp);

    for(int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
}

bool comp(pair <int, int> a, pair <int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}