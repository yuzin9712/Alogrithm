#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<string> makeArray(string word) {
    vector<string> arr;
    for(int i = 0; i < word.size() - 1; i++) {

        string subword = word.substr(i, 2);

        if(subword[0] >= 'a' && subword[0] <= 'z')
            subword[0] = subword[0] - ('a' - 'A');
        if(subword[1] >= 'a' && subword[1] <= 'z')
            subword[1] = subword[1] - ('a' - 'A');

        if((subword[0] >= 'A' && subword[0] <= 'Z') && (subword[1] >= 'A' && subword[1] <= 'Z')) {
            
            arr.push_back(subword);
        }
    }

    return arr;
}

pair<int, int> compare(vector<string> A, vector<string> B) {

    int i = 0, j = 0;
    vector<string> unions, intersections;

    while(i < A.size() && j < B.size()) {
        if(A[i] > B[j]) {
            unions.push_back(B[j]);
            j++;
        } else if (A[i] < B[j]) {
            unions.push_back(A[i]);
            i++;
        } else {
            unions.push_back(A[i]);
            intersections.push_back(A[i]);
            i++;
            j++;
        }
    }

    for(int k = i; k < A.size(); k++) {
        unions.push_back(A[k]);
    }

    for(int k = j; k < B.size(); k++) {
        unions.push_back(B[k]);
    }

    return make_pair(unions.size(), intersections.size());
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> A, B;
    pair<int, int> temp;
    double value;

    A = makeArray(str1);
    B = makeArray(str2);

    if(A.empty() && B.empty()) {
        value = 1;
    } else {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        temp = compare(A, B);

        value = (double)temp.second / temp.first;

    } 

    answer = (int)(value * 65536);
    
    return answer;
}

int main() {

    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    solution(str1, str2);

}