#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a, b;
    int n, input;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> input;
        a.push_back(input);
    }

    /* 이게 여기 있으면 메모리 초과가 발생 ,, 오ㅐ 그래,,?ㅡㅡ
    sort(a.begin(), a.end());
    */

    for(int i = 0; i < n; i++) {
        cin >> input;
        b.push_back(input);
    }

    sort(a.begin(), a.end());
    
    /*
    같은 수에 대해서 처리 안해주었더니 런타임 에러가 발생했다. 되도록 이면 greater less 를 사용하도록 하겠다.
    */
    sort(b.begin(), b.end(), greater<int> ());

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum = sum + (a[i] * b[i]);
    }

    cout << sum;
}