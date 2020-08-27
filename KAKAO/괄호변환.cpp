#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
  4-3. ')'를 다시 붙입니다. 
  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
  4-5. 생성된 문자열을 반환합니다.
*/

bool checkbalanced(string p) {
    stack<char> s;
    
    int left = 0, right = 0;

    for(int i = 0; i < p.size(); i++) {
        if(p[i] == '(') {
            left++;
            s.push('(');
        }
        else if (p[i] == ')') {
            right++;
            if(!s.empty() && s.top() == '(')  s.pop();
            else                s.push(')');
        }
    }

    /*올바른 괄호 문자열 = true, 균형잡힌 문자열 = false*/
    if(s.empty())   return true;
    return false;
    
}

int divide(string p) {
    int left = 0, right = 0, i;

    for(i = 0; i < p.size(); i++) {
        if(p[i] == '(') {
            left++;
        } else if (p[i] == ')') {
            right++;
        }

        if(left == right)   break;
        
    }

    return i;

}

string convert(string p) {
    string answer = "";
    for(int i = 1; i < p.size() - 1; i++) {

        if(p[i] == '(') answer.push_back(')');
        else            answer.push_back('(');
    }

    return answer;
}

string solution(string p) {
    string answer = "", w, u, v, temp;

    /*1번*/
    if(p == "") return "";
    else if(checkbalanced(p))   return p;
    else {
            /*2번*/
            int index = divide(p);

            u = p.substr(0, index + 1);
            v = p.substr(index + 1);

            /*3번 ~ 3-1번*/
            if(checkbalanced(u)) {
                answer += (u + solution(v));
            } else {
                /*4번*/

                temp = "(";

                temp += (solution(v) + ")");

                answer += (temp + convert(u));
            }

            return answer;
    }
}



int main() {

    string p;

    cin >> p;

    cout << solution(p);

}