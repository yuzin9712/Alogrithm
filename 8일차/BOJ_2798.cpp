#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, num;
    vector <int> arr;
    vector <int> temp;

    cin >> n >> m;

    temp.assign(n,0);

    for(int i = 0; i < 3; i++) {
        temp[i] = 1;
    }
    sort(temp.begin(), temp.end());

    for(int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    int min = 100000;
    int answer;

    do {
        int sum = 0;

        for(int i = 0; i < n; i++) {
            if(temp[i] == 1) {
                sum = sum + arr[i];
            }
        }

        if(sum <= m && m - sum < min) {
            min = m-sum;
            answer = sum;
        }
        
    }while(next_permutation(temp.begin(), temp.end()));

    
    cout << answer;

}