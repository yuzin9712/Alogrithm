#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string newline;
    int num;
    vector <int> score_arr;

    cin >> num;
    cin.ignore();

    /*이렇게 정수 값 입력 받고 문자열 입력받으면 제대로 동작을 안해!
    그래서 cin.ignore() 를 사용하여 해결해준다 ,,*/

    for(int i = 0; i < num; i++) {
        getline(cin, newline);
        int sum = 0;
        int score = 0;

        for(int j = 0; j < newline.size(); j++) {
            if(newline[j] == 'O') {
                score++;
                sum = sum + score;
            } else if(newline[j] == 'X') {
                score = 0;
            }
        }
        score_arr.push_back(sum);
    }

    for(int k = 0; k < score_arr.size(); k++) {
        cout << score_arr[k] << "\n";
    }

}