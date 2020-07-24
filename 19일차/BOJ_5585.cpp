#include <iostream>
#include <vector>
using namespace std;

int main() {
    int value, answer = 0;
    vector <int> money {500, 100, 50, 10, 5, 1};

    cin >> value;

    value = 1000 - value;

    for(int i = 0; i < money.size(); i++) {
        if(value >= money[i]) {
            answer = answer + value / money[i];
            value = value % money[i];
        }
    }

    cout << answer;
}