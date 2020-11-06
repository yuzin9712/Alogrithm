#include <iostream>
using namespace std;
int n, k;
int cnt;

bool num[1001];

int main() {
    cin >> n >> k;

    for(int i = 2; i <= n; i++) {
        if(!num[i]) {
            int p = i;

            for(int j = 1; j <= n; j++) {
                if(i * j <= n && !num[i * j]) {
                    num[i * j] = true;
                    cnt++;
                    if(cnt == k) {
                        cout << i * j;
                        return 0;
                    }
                } else if (i * j > n) {
                    break;
                }
            }
        }
    }
}