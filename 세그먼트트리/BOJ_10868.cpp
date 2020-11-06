#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000

int n, m;
int nums[100000];
int tree[100000 * 4];

int makeTree(int start, int end, int node) {
    
    if(start == end)    return tree[node] = nums[start];

    int mid = (start + end) / 2;
    return tree[node] = min(makeTree(start, mid, node * 2), makeTree(mid + 1, end, node * 2 + 1));

}

int findMin(int start, int end, int left, int right, int node) {
    if(start > right || end < left) {
        return INF;
    } else if (left <= start && right >= end) {
        return tree[node];
    } else {
        int mid = (start + end) / 2;
        int a = findMin(start, mid, left, right, node * 2);
        int b = findMin(mid + 1, end, left, right, node * 2 + 1);
        return min(a, b);
    }
}

void input() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    makeTree(0, n - 1, 1);

    // for(int i = 1; i < 33; i++) {
    //     cout << tree[i] << " ";
    // }
}

void solution() {
    int a, b;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << findMin(0, n - 1, a - 1, b - 1, 1);
        cout << "\n";
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}