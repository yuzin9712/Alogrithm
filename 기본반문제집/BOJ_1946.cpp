#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return (a.first < b.first) ? true : false;
}

int main() {
    int t, n, x, y;

    cin >> t;

    for(int i = 0; i < t; i++) {
        int answer = 1;
        cin >> n;
        vector<pair<int, int>> arr1;

        for(int j = 0; j < n; j++) {
            cin >> x >> y;

            arr1.push_back(make_pair(x, y));

        }

        sort(arr1.begin(), arr1.end(), comp);

        int min = arr1[0].second;

        /*이중 루프로 구하면 시간초과 발생 ,,*/
        for(int k = 1; k < arr1.size(); k++) {
            if(arr1[k].second < min) {
                min = arr1[k].second;
                answer++;
            }
        }

        cout << answer << "\n"; 


    }
}