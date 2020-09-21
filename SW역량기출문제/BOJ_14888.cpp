#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int MIN = 1000000000, MAX = -1000000000;
int n, num;
vector<int> numbers;
vector<char> operators;
int cnt[4];
int sum = 0;

void input() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    for(int i = 0; i < 4; i++) {
        cin >> cnt[i];
        sum += cnt[i];
        
        for(int j = 0; j < cnt[i]; j++) {
            if(i == 0) {
                operators.push_back('+');
            } else if(i == 1) {
                operators.push_back('-');
            } else if(i == 2) {
                operators.push_back('*');
            } else {
                operators.push_back('/');
            }
        }
    }
}

void solution() {
    sort(operators.begin(), operators.end());

    do
    {
        string copyoperators = "";
        vector<int> copynumbers;

        copynumbers = numbers;

        for(int i = 0; i < operators.size(); i++) {
            copyoperators += operators[i];
        }
        // cout << copyoperators << " ";

        int j = 0;
        
        for(int i = 1; i < copynumbers.size(); i++) {
            int num1 = copynumbers[i - 1];
            int num2 = copynumbers[i];
            int value;

            if(copyoperators[j] == '+') {
                value = num1 + num2;
            } else if(copyoperators[j] == '-') {
                value = num1 - num2;
            } else if(copyoperators[j] == '*') {
                value = num1 * num2;
            } else if(copyoperators[j] == '/') {
                value = num1 / num2;
            }
            
            j++;
            copynumbers[i] = value;
        }

        // cout << copynumbers[copynumbers.size() - 1] << "\n";

        if(MIN > copynumbers[copynumbers.size() - 1]) {
            MIN = copynumbers[copynumbers.size() - 1];
        }

        if(MAX < copynumbers[copynumbers.size() - 1]) {
            MAX = copynumbers[copynumbers.size() - 1];
        }
        
    } while (next_permutation(operators.begin(), operators.end()));
    
}

int main() {
    input();
    solution();
    cout << MAX << "\n" << MIN;


}