#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> newarr;

void makeArray(string word) {
    int i = 1, j = 1, k = 0, index = 0, sum = 0;
    string num = "";

    while(i < word.size() - 1) {
        if(word[i] != '{' && word[i] != '}' && word[i] != ',') {

            j = i + 1;

            while(word[j] != '{' && word[j] != '}' && word[j] != ',') {
                j++;
            }

            num = word.substr(i, j - i);

            sum += (stoi(num));

            i = j;
        } else {
            if(word[i] == '}') {
                newarr.push_back(sum);
                sum = 0;
            }

            i++;
        }
    }

    sort(newarr.begin(), newarr.end());
}

vector<int> solution(string s) {
    vector<int> answer;
    int value = 0;

    makeArray(s);

    for(int i = 0; i < newarr.size(); i++) {
        if(value < newarr[i]) {
            answer.push_back(newarr[i] - value);
            value = newarr[i];
        }
    }

    return answer;
}