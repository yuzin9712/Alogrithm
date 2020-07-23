#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int x, y;
    vector <pair <int, int>> tri;

    for(int i = 0; i < 3; i++) {
        cin >> x >> y;

        tri.push_back(make_pair(x, y));
    }
    
    /*
    XOR 사용해서 구할 수 있다.
    5 와 5를 XOR 하면
    101 xor 101 => 000
    얘를 다시 다른 값 2와 xor 하면 000 xor 010 => 010
    다른 값 하나가 나옴!!!
    */
    x = tri[0].first^tri[1].first^tri[2].first;
    y = tri[0].second^tri[1].second^tri[2].second;

    cout << x << " " << y;

}