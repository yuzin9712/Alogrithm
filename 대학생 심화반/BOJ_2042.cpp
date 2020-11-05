#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int n, m, k;
long long num[1000000];
long long *tree;
int updateCnt = 0, printCnt = 0;

long long makeTree(int start, int end, int index) {
    if(start == end) {
        return tree[index] = num[start];
    } else {
        int mid = (start + end) / 2;
        return tree[index] = makeTree(start, mid, index * 2) + makeTree(mid + 1, end, index * 2 + 1);
    }
}

void input() {

    cin >> n >> m >> k;
    tree = (long long *)malloc(sizeof(long long) * 4 * n);

    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    makeTree(0, n - 1, 1);    
}

long long getPartialSum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) {
        return 0;
    }

    /*여기 다시 이해해,,,,ㅠ 아우*/
    if(start >= left && right >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return getPartialSum(start, mid, node * 2, left, right) + getPartialSum(mid + 1, end, node * 2 + 1, left, right);
}

void updateNode(int start, int end, int node, int index, int diff) {
    if(index < start || index > end) {
        return;
    } else {
        tree[node] += diff;

        if(start == end) return;

        int mid = (start + end) / 2;
        updateNode(start, mid, node * 2, index, diff);
        updateNode(mid + 1, end, node * 2 + 1, index, diff);
    }
}

void solution() {
    int a, b, c;

    while(true) {
        cin >> a >> b >> c;

        if(a == 1) {
            updateNode(0, n - 1, 1, b - 1, c - num[b - 1]);
            num[b - 1] = c;
            updateCnt++;
        } else {
            cout << getPartialSum(0, n - 1, 1, b - 1, c - 1) << "\n";
            printCnt++;
        }

        if(printCnt == k && updateCnt == m) {
            break;
        }
    }
}

int main() {
    input();
    solution();
}