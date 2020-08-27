#include <iostream>
#include <string>
#include <vector>

using namespace std;

string word;

int compare(string s, int numOfchar) {
    vector<string> arr;

    string answer = "";

    for(int i = 0; i < s.size(); i += numOfchar) {
        arr.push_back(s.substr(i, numOfchar));
    }

    string criteria = arr[0];
    int cnt = 1;

    for(int i = 1; i < arr.size(); i++) {
        if(criteria == arr[i]) {
            cnt++;
        } else {
            if(cnt == 1)    answer += criteria;
            else            answer += to_string(cnt) + criteria;
            cnt = 1;
            criteria = arr[i];
        }
    }

    if(cnt == 1)    answer += criteria;
    else            answer += to_string(cnt) + criteria;

    return answer.size();
}

int solution(string s) {
    int answer = 0, min = 1000000000;

    if(s.size() == 1) {
        return 1;
    }

    for(int i = 1; i <= s.size() / 2; i++) {
        int num = compare(s, i);
        if(min > num) {
            min = num;
        }
    }

    return min;
}



int main() {
    cin >> word;

    cout << solution(word);
}