#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, l, input, answer = 0;
    double left, right;
    vector<int> arr;

    cin >> n >> l;

    for(int i = 0; i < n; i++) {
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    left = arr[0] - 0.5;
    right = left + l;
    answer++;

    for(int i = 1; i < n; i++) {
        if((arr[i] + 0.5) > right) {
            answer++;
            left = arr[i] - 0.5;
            right = left + l;
            // cout << "left : " << left << " right :" << right << "\n";
            // answer++;
        }
    }

    cout << answer;
}