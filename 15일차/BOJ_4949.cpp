#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

    char c;
    
    while(1) {

        stack <char> s;
        string line;

        while(1) {
            cin >> line;
            

            if(c == '.') {
                break;
            } else if (c == '(' || c == ')' || c == '[' || c == ']') {
                if(c == '(' || c == '[') {
                    s.push(c);
                } else { /*오른쪽 괄호 - 짝이면 pop 아니면 push*/
                    if(s.empty()) {
                        s.push(c);
                    } else {
                        if(s.top() == '(' && c == ')') {
                            s.pop();
                        } else if (s.top() == '[' && c == ']') {
                            s.pop();
                        } else {
                            s.push(c);
                        }
                    }
                }
            }
        }

    if(s.empty()) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    }
}