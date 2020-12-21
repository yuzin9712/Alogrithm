#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int length = number.size() - k;
    int index = 0;

    while(length != 0) {
        int cnt = number.size() - length + 1;
        answer += *max_element(number.begin() + index, number.begin() +  cnt);
        index = max_element(number.begin() + index, number.begin() +  cnt) - number.begin() + 1; //해당 element의 index 구하기 - distance로도 가능

        length--;
    }




    return answer;
}