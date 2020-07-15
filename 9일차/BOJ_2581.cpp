#include <iostream>
#include <math.h>
using namespace std;

/*1이 소수가 아님 ㅡㅡ*/

int main() {
    int m, n;
    int min = 10000;
    int sum = 0;

    cin >> m >> n;

    if(n == 1) {
        cout << -1 << "\n";
        return 0;
    } else {
        if(m == 1) {
            m = 2;
        }

        for(int x = m; x <= n; x++) {
            bool flag = true;

            for(int i = 2; i <= sqrt(x); i++) {
                if(x%i == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                sum = sum + x;
                if(min > x) {
                    min = x;
                }
            } else {
                continue;
            }
        }

        if(sum == 0 && min == 10000) {
            cout << -1;
            return 0;
        }

        cout << sum << "\n" << min;
        return 0;
    }
}