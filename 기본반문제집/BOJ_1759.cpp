#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

/*
consonant 자음
vowel 모음
*/
int l, c;
char input;
vector<char> arr;

void DFS(int v, string num, int con, int vow) {
    if(num.size() == l) {
        if(con >= 2 && vow >= 1)    cout << num << "\n";
        return ;
    }

    if(v >= arr.size()) return ;

    char x = arr[v];

    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        DFS(v + 1, num + arr[v], con, vow + 1);
    }
    else {
        DFS(v + 1, num + arr[v], con + 1, vow);
    }

    DFS(v + 1, num, con, vow);
    
}

int main() {
    cin >> l >> c;

    for(int i = 0; i < c; i++) {
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    DFS(0, "", 0, 0);
}