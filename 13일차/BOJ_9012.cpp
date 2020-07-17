#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

    int n;

    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
        stack <char> s;
        string line;
        getline(cin, line);

        for(int j = 0; j < line.size(); j++) {
            if(line[j] == '(') {
                s.push('(');
            }else {
                if(!s.empty()) {
                    if(s.top() == '(') {
                        s.pop();
                    } else {
                        s.push(')');
                    }
                } else {
                    s.push(')');
                }
            }
        }

        if(s.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n"; 
        }

    }

}