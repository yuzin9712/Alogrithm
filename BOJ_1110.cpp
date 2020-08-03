#include <iostream>
#include <string>
using namespace std;

string number;
int answer;

void solution(string num) {
    answer++;

    int sum = (num[0] - '0') + (num[1] - '0');

    string newnum = num[1] + to_string((sum % 10));

    // cout << newnum << "\n";

    if(newnum.size() < 2) {
        newnum = '0' + newnum;
    }

    if(newnum == number) {
        return ;
    }

    solution(newnum);

}

int main() {

    cin >> number;

    if(number.size() < 2) {
        number = '0' + number;
    }

    solution(number);

    cout << answer;
}