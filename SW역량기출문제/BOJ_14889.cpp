#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int arr[25][25];
int n, answer = 1000000000;

void input() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

}

void solution() {
    vector<bool> temp(n, false);
    vector<int> a, b;

    for(int i = 0; i < n / 2; i++) {
        temp[i] = true;
    }

    sort(temp.begin(), temp.end());

    do
    {
        int sumA = 0, sumB = 0;

        for(int i = 0; i < temp.size(); i++) {
            if(temp[i])
                a.push_back(i + 1);
            else
                b.push_back(i + 1);
        }
  
        for(int i = 0; i < a.size(); i++) {
            for(int j = i + 1; j < a.size(); j++) {
                sumA += arr[a[i] - 1][a[j] - 1];
                sumA += arr[a[j] - 1][a[i] - 1];
            }
        }

        for(int i = 0; i < b.size(); i++) {
            for(int j = i + 1; j < b.size(); j++) {
                sumB += arr[b[i] - 1][b[j] - 1];
                sumB += arr[b[j] - 1][b[i] - 1];
            }
        }

        if(abs(sumA - sumB) < answer)
            answer = abs(sumA - sumB);

        a.clear();  b.clear();

    } while (next_permutation(temp.begin(), temp.end()));
    
}

int main() {

    input();
    solution();
    cout << answer;

}