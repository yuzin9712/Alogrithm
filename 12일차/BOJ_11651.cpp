#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool comp(pair <int, int> a, pair <int, int> b);

int main() {
    vector <pair <int, int>> arr;
    int n, x, y;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        arr.push_back(make_pair(x,y));
    }

    sort(arr.begin(), arr.end(), comp);

    for(int j = 0; j < n; j++) {
        cout << arr[j].first << " " << arr[j].second << "\n";
    }

}

bool comp(pair <int, int> a, pair <int, int> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}