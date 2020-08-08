#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair <char, int>> arr;
vector<int> numbers(10);
int answer;

bool comp(pair<char, int> a, pair<char, int> b) {
    if(a.second == b.second)    return (a.first < b.first) ? true : false;
    return (a.second < b.second) ? true : false;
}

void rule1() {
    bool type = true;
    int score;

    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i].first != arr[i + 1].first) {
            type = false;
            break;
        }
        if(arr[i].second + 1 != arr[i + 1].second) {
            type = false;
            break;
        }
    }

    if(type) {
        score = 900 + arr[4].second;
        if(score > answer) {
            answer = score;
        }
    }
}

void rule2() {
    
    int score;

    for(int i = 0; i < 10; i++) {
        if(numbers[i] == 4) {
            score = 800 + i;
            if(score > answer)  answer = score;
            break;
        }
    }

}

void rule3() {
    int score;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(numbers[i] == 3 && numbers[j] == 2) {
                score = 700 + (i * 10 + j);
                if(score > answer)  answer = score;
                break;
            }
        }
    }
}

void rule4() {
    bool type = true;
    int score;

    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i].first != arr[i + 1].first) {
            type = false;
            break;
        }
    }

    if(type) {
        score = 600 + arr[4].second;
        if(score > answer) {
            answer = score;
        }
    }
}

void rule5() {
    bool type = true;
    int score;

    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i].second + 1 != arr[i + 1].second) {
            type = false;
            break;
        }
    }
    if(type) {
        score = 500 + arr[4].second;
        if(score > answer) {
            answer = score;
        }
    }
}

void rule6() {

    int score;
    for(int i = 0; i < 10; i++) {
        if(numbers[i] == 3) {
            score = 400 + i;
            if(score > answer) {
                answer = score;
                break;
            }
        }
    }
}

void rule7() {
    int score;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(i != j && numbers[i] == 2 && numbers[j] == 2) {
                score = 300 + (j * 10 + i);
                if(score > answer) {
                    answer = score;
                }
                break;
            }
        }
    }
}

void rule8() {
    int score;

    for(int i = 0; i < 10; i++) {
        if(numbers[i] == 2) {
            score = 200 + i;
            if(score > answer) {
                answer = score;
                break;
            }
        }
    }
}

void rule9() {
    if(answer == 0) {
        answer = 100 + arr[4].second;
    }
}

int main() {
    char color;
    int num;

    for(int i = 0; i < 5; i++) {
        cin >> color >> num;
        arr.push_back(make_pair(color, num));
        numbers[num]++;
    }

    sort(arr.begin(), arr.end(), comp);

    rule1();
    rule2();
    rule3();
    rule4();
    rule5();
    rule6();
    rule7();
    rule8();
    rule9();

    cout << answer;
}