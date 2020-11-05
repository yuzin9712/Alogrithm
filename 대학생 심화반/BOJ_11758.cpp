#include <iostream>
#include <vector>
using namespace std;

int x1, x2, x3;
int y1, y2, y3;

void input() {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
}

void solution() {
    int value = (y2 -y1) * x3 - (x2 - x1) * y3 - (x1 * y2) + (x2 * y1);
    if(value == 0) {
        cout << 0;
    } else if (value > 0) {
        cout << -1;
    } else {
        cout << 1;
    }
    return ;

}

int main() {
    input();
    solution();

}