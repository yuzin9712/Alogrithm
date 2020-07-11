#include <iostream>
using namespace std;

int solution (int n);

int main() {
    int n;

    cin >> n;
    
    /*0!은 0이 아니라 1이야!!*/
    if(n == 0) {
        cout << 1;
    }else {
        cout << solution(n);
    }
}

int solution (int n) {
    if(n == 1) {
        return 1;
    }

    return n * solution(n-1);
}