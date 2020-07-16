#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool comp(pair <string, int> a, pair <string, int> b);

int main() {

    int n;
    string word;
    vector <pair <string, int>> arr;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> word;

        arr.push_back(make_pair(word,word.size()));
    }

    /*원하는 비교조건으로 정렬한 후 중복제거!*/
    sort(arr.begin(), arr.end(), comp);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());


    for(int j = 0; j < arr.size(); j++) {
        cout << arr[j].first << "\n";
    }

}

bool comp(pair <string, int> a, pair <string, int> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}