#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>
using namespace std;

char priorty[6][3] = {
    {'*', '+', '-'},
    {'*', '-', '+'},
    {'+', '*', '-'},
    {'+', '-', '*'},
    {'-', '*', '+'},
    {'-', '+', '*'}
};

pair<vector<long long>, vector<char>> makeArray(string expression) {
    vector<long long> numbers;
    vector<char> operators;

    char *str_buff = new char[110];
    strcpy(str_buff, expression.c_str());

    char *tok = strtok(str_buff, "*+-");

    while(tok != nullptr) {
        numbers.push_back(stoi(string(tok)));
        tok = strtok(nullptr, "*+-");
    }

    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] == '-' || expression[i] == '+' || expression[i] == '*') {
            operators.push_back(expression[i]);
        }
    }

    return make_pair(numbers, operators);
}

long long calculate(vector<long long> numbers, vector<char> operators, int index) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < operators.size(); j++) {
            if(operators[j] == priorty[index][i]) {
                // cout << numbers[j] << operators[j] << numbers[j + 1] << " = "; 
                if(operators[j] == '*') {
                    numbers[j] = numbers[j] * numbers[j + 1];
                } else if (operators[j] == '+') {
                    numbers[j] = numbers[j] + numbers[j + 1];
                } else if (operators[j] == '-') {
                    numbers[j] = numbers[j] - numbers[j + 1];
                }
                // cout << numbers[j] << "\n";
                operators.erase(operators.begin() + j);
                numbers.erase(numbers.begin() + j + 1);

                j--;
            }
        }
    }

    return numbers[0];
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> numbers;
    vector<char> operators;

    numbers = makeArray(expression).first;
    operators = makeArray(expression).second;

    for(int i = 0; i < 6; i++) {
        long long num = abs(calculate(numbers, operators, i));
        if(num > answer)
            answer = num;
    }

    // cout << answer;
    

    return answer;
}

int main () {
    string line;
    cin >> line;
    solution(line);
}