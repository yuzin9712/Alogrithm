#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int input;
    vector <int> arr;

    for(int i = 0; i < 10; i++) {
        cin >> input;
        input %= 42;
        arr.push_back(input);
    }

    /*배열에서 중복 제거*/
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()) ,arr.end());

    cout << arr.size();

}