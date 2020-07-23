#include <iostream>
using namespace std;

int main() {
    int n, i = 1 , j = 1, sum;
    int x = 1, y = 1;

    cin >> n;

    while((i * (i+1))/2 < n) {
        i++;
    }

    j = (i * (i-1))/2 + 1;
    // cout << j;

    if(i%2 == 0) {
        x = i;
        y = 1;

        while(j != n) {
            x--;
            y++;
            j++;
        }
    } else {
        x = 1;
        y = i;
        while(j != n) {
            x++;
            y--;
            j++;
        }
    }

    cout << y << "/" << x;



}