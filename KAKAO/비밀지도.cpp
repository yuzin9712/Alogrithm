#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector<bitset<16>> makeBitArray(int n, vector<int> arr) {
    vector<bitset<16>> bitarr;

    for(int i = 0; i < n; i++) {
        bitarr.push_back(arr[i]);
    }

    return bitarr;
}

vector<string> comp(int n, vector<bitset<16>> arr1, vector<bitset<16>> arr2) {
    bitset<16> bits;
    vector<string> arr;
    for(int i = 0; i < n; i++) {
        string line = "";
        bits = (arr1[i] |= arr2[i]);
        for(int j = n - 1; j >= 0; j--) {
            if(bits[j] == 1)
                line += "#";
            else if (bits[j] == 0)
                line += " ";
        }
        // cout << line;
        arr.push_back(line);
        // cout << "\n";
    }

    return arr;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<bitset<16>> bitarr1, bitarr2;

    bitarr1 = makeBitArray(n, arr1);
    bitarr2 = makeBitArray(n, arr2);

    answer = comp(n, bitarr1, bitarr2);


    return answer;
}

pair<vector<int>, vector<int>> input(int n) {
    int num;
    vector<int> arr1, arr2;

    for(int i = 0; i < n; i++) {
        cin >> num;
        arr1.push_back(num);
    }

    for(int j = 0; j < n; j++) {
        cin >> num;
        arr2.push_back(num);
    }

    return make_pair(arr1, arr2);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr1, arr2;

    pair<vector<int>, vector<int>> value = input(n);

    solution(n, value.first, value.second);
}