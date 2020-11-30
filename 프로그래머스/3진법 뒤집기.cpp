#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<int> num;

    while(n >= 3) {
        num.push_back(n % 3);
        n = n / 3;
    }

    num.push_back(n);

    for(int i = 0; i < num.size(); i++) {
        answer += num[num.size() - i - 1] * pow(3, i);
    }
    return answer;
}

int main() {

    int n;
    cin >> n;
    solution(n);

}