#include <iostream>
using namespace std;

int check(int left, int num, int right);

int t, h, w, n;

int main() {

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> h >> w >> n;

        int floor = n % h;

        if(floor == 0) {
            floor = h;
        }

        floor = floor * 100;

        int ho = check(1, n, h);

        cout << floor + ho << "\n";

    }

 
}

int check(int left, int num, int right) {
    if(left <= num && num <= right) {
        return right / h;
    } else {
        return check(right+1, num, right + h);
    }
}