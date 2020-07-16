#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cin >> n;

    if(n == 1) {
        cout << "666";
    } else {
        int x = 1;
        for(int i = 1666; ;i++) {
            string number = to_string(i);

            if(number.find("666") == string::npos) {
                continue;
            } else {
                x++;
                if(x == n) {
                    cout << number;
                    return 0;
                }
            }
        } 
    }
    
}