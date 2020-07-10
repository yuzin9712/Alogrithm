#include <iostream>
using namespace std;

void solution(int a, int b, int i);

int n;

int main() {

    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    } else {
        solution(2,7,1);
    }
}

void solution(int a, int b, int i) {
    int x = a;
    int y = b;
    int ni = i;

    if(n >= x && n <= b) {
        cout << ni+1;
        return ;
    } else {
        solution(y+1, y + (ni+1)*6, ni+1);
    }
}