#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, minindex, sum = 0, answer = 0;
    vector <int> times(1000);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> times[i];
    }

    sort(times.begin(), times.begin() + n);


    for(int j = 0; j < n; j++) {
        sum = sum + times[j];
        answer = answer + sum;
    }

    cout << answer;
}