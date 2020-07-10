#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;

    cin >> t;

    for(int i = 0; i < t; i++) {

        int r;
        string s;
        string p;

        cin >> r >> s;

        for(int j = 0; j < s.size(); j++) {
            for(int k = 0; k < r; k++) {
                p.push_back(s[j]);
            }
        }

        cout << p << "\n";
    }
}