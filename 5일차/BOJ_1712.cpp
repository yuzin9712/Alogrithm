#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    int x;

    x = a / (c - b);

    if(c-b <= 0) {
        cout << -1;
        return 0;
    } else {
        cout << x + 1;
        return 0;
    }
}