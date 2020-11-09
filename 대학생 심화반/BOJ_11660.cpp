#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
int arr[1030][1030];
int sum[1030][1030];

int main() {
    int x1, y1, x2, y2;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            sum[i][j] = sum[i][j - 1] + arr[i][j];
        }
    }

    for(int i = 1; i <= m; i++) {
        int result = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for(int j = x1; j <= x2; j++) {

            result = result + (sum[j][y2] - sum[j][y1 - 1]);
        }
        printf("%d\n", result);
    }

}