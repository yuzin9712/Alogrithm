#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    vector<int> arr, temp;
    int n, num, max = 0, sum = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());


    do {
        sum = 0;

        for(int i = 0; i < n - 1; i++) {
            sum = sum + abs(arr[i] - arr[i + 1]);
        }
        if(max < sum) {
            max = sum;
        }
    }while(next_permutation(arr.begin(), arr.end()));

    cout << max;

}