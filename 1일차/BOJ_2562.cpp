#include <iostream>
using namespace std;

int main() {
    int input;
    int max = 0;
    int maxindex = 0;

    for(int i = 1; i <= 9; i++) {
        cin >> input;
        if(max <= input) {
            max = input;
            maxindex = i;
        }
    }

    cout << max << "\n" << maxindex;
}