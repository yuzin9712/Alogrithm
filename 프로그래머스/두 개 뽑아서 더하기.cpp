#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {

    vector<int> answer;

    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    /*vector의 중복 원소 제거*/
    sort(answer.begin(), answer.end());

    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}

vector<int> solution2(vector<int> numbers) {
    vector<int> answer;
    set<int> num;

    set<int>::iterator iter;

    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            num.insert(numbers[i] + numbers[j]);
        }
    }

    answer.assign(num.begin(), num.end());

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return answer;
}

int main() {

    int n;
    cin >> n;

    vector<int> numbers(n);

    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    solution2(numbers);

}