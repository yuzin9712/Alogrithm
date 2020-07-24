#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool comp(pair <int, int> a, pair <int, int> b);

int main () {
    int n, start, end;
    int answer = 1;
    /*<시작시간, 끝나는시간>*/
    vector <pair <int, int>> arr;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> start >> end;

        arr.push_back(make_pair(start, end));

    }

    sort(arr.begin(), arr.end(), comp);

    start = arr[0].first;
    end = arr[0].second;

    for(int j = 1; j < arr.size(); j++) {
        if(arr[j].first >= end) {
            end = arr[j].second;
            answer++;
        }
    }

    cout << answer;

}

bool comp(pair <int, int> a, pair <int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}