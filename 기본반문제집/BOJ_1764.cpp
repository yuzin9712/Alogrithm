#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, i1, i2, result, answer;
string word;
vector<string> arr1, arr2, arr3;

void input() {
    for(int i = 0; i < n; i++) {
        cin >> word;
        arr1.push_back(word);
    }

    for(int i = 0; i < m; i++) {
        cin >> word;
        arr2.push_back(word);
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

void solution() {
    while(1) {

        /*while 조건에 i1 < n || i2 < m 을 넣으면 왜 런타임 에러가 발생하는가?*/
        if(i1 >= n || i2 >= m) {
            break;
        }

        // cout << arr1[i1] << " " << arr2[i2] << "\n";
        
        if(arr1[i1] == arr2[i2]) {
            arr3.push_back(arr1[i1]);
            i1++;
            i2++;

        }else if(arr1[i1] < arr2[i2]) {
            i1++;

        }else if(arr1[i1] > arr2[i2]) {
            i2++;

        }
    }
}

void output() {
    cout << arr3.size() << "\n";

    for(int i = 0; i < arr3.size(); i++) {
        cout << arr3[i] << "\n";
    }
    // cout << "answer : " << answer;
}

int main() {

    cin >> n >> m;

    input();

    solution();

    output();




}