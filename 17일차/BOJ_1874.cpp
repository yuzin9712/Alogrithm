#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    int n, num, current = 0, i = 0;
    stack <int> s;
    vector <char> answer;
    vector <int> arr;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    /*스택이 비어있는 상태에서 s.top()을 쓰면 런타임에러!!!!!!!!!! 꼭 체크해주어야함.*/

    while(current != arr.size()) {
        if(!s.empty() && s.top() > arr[current]) {
            cout << "NO";
            return 0;
        } else {
            if(s.empty() || !s.empty() && s.top() < arr[current]) {

                while(1) {
                    i++;
                    s.push(i);
                    answer.push_back('+');

                    if(s.top() == arr[current]) {
                        break;
                    }
                }

                s.pop();
                answer.push_back('-');
                current++;

            } else if (!s.empty() && s.top() == arr[current]) {
                s.pop();
                answer.push_back('-');
                current++;
            }
        }
    }

    for(int k = 0; k < answer.size(); k++) {

        cout << answer[k] << "\n";

    }

}