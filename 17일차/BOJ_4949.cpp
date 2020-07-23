#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*문제 이해를 잘못하고 삽질함 ㅡㅡ*/

int main() {
    
    while(1) {

        stack <char> s;
        string line;

        getline(cin, line);

        for(int i = 0; i < line.size(); i++) {

            if(line[i] == '.' && line.size() == 1) {
                return 0;
            } else if (line[i] == '(' || line[i] == ')' || line[i] == '[' || line[i] == ']') {
                if(line[i] == '(' || line[i] == '[') {
                    s.push(line[i]);
                } else { /*오른쪽 괄호 - 짝이면 pop 아니면 push*/
                    if(s.empty()) {
                        s.push(line[i]);
                    } else {
                        if(s.top() == '(' && line[i] == ')') {
                            s.pop();
                        } else if (s.top() == '[' && line[i] == ']') {
                            s.pop();
                        } else {
                            s.push(line[i]);
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