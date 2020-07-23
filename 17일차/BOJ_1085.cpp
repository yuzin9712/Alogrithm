#include <iostream>
#include <algorithm>
using namespace std;

/*주어진 점하고만 비교하면 x x축 y축 하고도 비교해야함!*/

int main() {
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    cout << ((min(w-x, x) > min(h-y, y) ? min(h-y,y) : min(w-x, x)));
}