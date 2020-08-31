/*투포인터*/
#include <iostream>
using namespace std;

int n, l = -1, r = -1, number, answer = 0;
long long m, sum = 0;
int arr[10010];

void input() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> number;
        arr[i] = number;
    }
}

void solution() {
    /*범위주의!!*/
    while(l < n && r < n) {
        if(sum < m) {
            r++;
            sum += arr[r];
        }
        else {
            l++;
            sum -= arr[l];
        }

        if(sum == m)
            answer++;
    }
}

int main() {
    input();
    solution();
    cout << answer;
}