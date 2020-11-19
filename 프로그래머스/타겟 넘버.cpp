#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

// int getEquation(vector<int> numbers, int target, int size, int numOfminus) {
//     int cnt = 0;

//     vector<bool> temp(size, false);

//     for(int i = 0; i < numOfminus; i++) {
//         temp[i] = true;
//     }

//     sort(temp.begin(), temp.end());

//     do
//     {
//         int sum = 0;

//         for(int i = 0; i < size; i++) {
//             if(temp[i]) {
//                 cout << "-" << " ";
//                 sum += (-1 * numbers[i]);
//             } else if (!temp[i]) {
//                 cout << "+" << " ";
//                 sum += numbers[i];
//             }
//             cout << numbers[i] << " ";
//         }

//         if(sum == target) {
//             cnt++;
//         }
//         cout << " = " << sum << "\n";
//     } while (next_permutation(temp.begin(), temp.end()));

//     return cnt;
// }

void DFS(vector<int> numbers, int target, int v, int sum) {
    if(v >= numbers.size()) {
        if(target == sum) {
            answer++;
        }
        return;
    }

    DFS(numbers, target, v + 1, sum + numbers[v]);
    DFS(numbers, target, v + 1, sum - numbers[v]);
}

int solution(vector<int> numbers, int target) {

    DFS(numbers, target, 1, numbers[0]);
    DFS(numbers, target, 1, -1 * numbers[0]);

    return answer;
}

// int solution(vector<int> numbers, int target) {
//     int answer = 0;

//     for(int i = 0; i < numbers.size(); i++) {
//         answer += getEquation(numbers, target, numbers.size(), i);
//         cout << "\n";
//     }

//     return answer;
// }

int main() {
    vector<int> numbers;
    int target, cnt, num;

    cin >> cnt;

    for(int i = 0; i < cnt; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    cin >> target;

    cout << "result !! " << solution(numbers, target);
}