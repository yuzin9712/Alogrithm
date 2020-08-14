// /*틀렸다 ㅡㅡ*/
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <utility>
// using namespace std;

// bool comp(pair<int, bool> a, pair<int, bool> b) {
//     if(a.first == b.first) {
//         return (a.second > b.second) ? false : true;
//     }
//     return (a.first > b.first) ? true : false;
// }

// int main() {
//     int n, p, input, score;
//     vector<pair<int, bool>> arr;

//     cin >> n >> score >> p;

//     for(int i = 0; i < n; i++) {
//         cin >> input;
//         arr.push_back(make_pair(input, 0));
//     }

//     arr.push_back(make_pair(score, 1));

//     sort(arr.begin(), arr.end(), comp);


//     int rank = 1, cur = arr[0].first, index = 0, answer;

//     for(int i = 1; i < arr.size(); i++) {

//         if(arr[i].first != cur) {
//             rank = i + 1;
//         }

//         cur = arr[i].first;

//         // cout << arr[i].first << " " << arr[i].second << " " << rank << "\n";

//         if(arr[i].second == 1 && arr[i].first == score) {
//             index = i;
//             answer = rank;
//             break;
//         }

//     }

//     if(index >= p) {
//         cout << - 1;
//     } else {
//         cout << rank;
//     }

//     return 0;

// }
#include <iostream>

using namespace std;

int main() {
    int n, newscore, p, input, rank = 0, size = 0;

    cin >> n >> newscore >> p;

    for(int i = 0; i < n; i++) {
        cin >> input;
        if(input > newscore)    rank++;
        if(input >= newscore)   size++;
    }

    if(size + 1 > p)    cout << -1;
    else                cout << rank + 1;
    
}