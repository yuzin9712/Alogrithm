#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

pair<vector<int>, vector<int>> eraseDup(vector<int> lost, vector<int> reserve) {
    vector<int> realost;
    vector<int> realreserve;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int i = 0, j = 0;

    while(i < lost.size() || j < reserve.size()) {
        if(lost[i] == reserve[j]) {
            i++;
            j++;
        } else if (lost[i] > reserve[j]) {
            realreserve.push_back(reserve[j]);
            j++;
        } else if (lost[i] < reserve[j]) {
            realost.push_back(lost[i]);
            i++;
        }
    }

    return {realost, realreserve};
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    pair<vector<int>, vector<int>> real;
    vector<int> arr(n + 1, 1);

    real = eraseDup(lost, reserve);

    for(int i = 0; i < real.first.size(); i++) {
        // cout << real.first[i] << " ";
        arr[real.first[i]]--;
    }

    cout << "\n";

    for(int i = 0; i < real.second.size(); i++) {
        // cout << real.second[i] << " ";
        arr[real.second[i]]++;
    }

    for(int i = 1; i < arr.size() - 1; i++) {
        if(arr[i] == 0 && arr[i + 1] == 2) {
            arr[i]++;   arr[i + 1]--;
        } else if (arr[i] == 2 && arr[i + 1] == 0) {
            arr[i]--;   arr[i + 1]++;
        }
    }

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > 0)  answer++;
    }



    return answer;
}