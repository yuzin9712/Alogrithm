#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b);

int main() {
    int n;

    cin >> n;

    string number = to_string(n);

    sort(number.begin(), number.end(), desc);

    cout << number;
}

/*
default 가 오름차순
내림차순을하려면 다음과 같이 비교를 위한 함수 만들어야함.
*/
bool desc(int a, int b) {
    return a > b;
}