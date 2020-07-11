#include <iostream>
using namespace std;

int solution(int n);

int main() {
    int n;

    cin >> n;

    cout << solution(n);
}

int solution(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return solution(n-1) + solution(n-2);
    }
}