#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string a, b;

    cin >> a >> b;

    for(int i = 0; i < 3; i++) {
        if(a[2-i] > b[2-i]) {
            reverse(a.begin(), a.end());
            cout << a;
            break;
        } else if (a[2-i] < b[2-i]) {
            reverse(b.begin(), b.end());
            cout << b;
            break;
        }
    }
}