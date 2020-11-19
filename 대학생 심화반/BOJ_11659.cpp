/*누적합*/
#include <cstdio>
using namespace std;

int n, m;
int arr[100001];
int sum[100001];


int main() {
    
    int a, b;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        sum[i] = sum[i - 1] + arr[i];
    }
    
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", sum[b] - sum[a - 1]);
    }
    
}