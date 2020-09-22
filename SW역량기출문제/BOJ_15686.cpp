#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#define DISTANCE(x1, y1, x2, y2)    (abs(x2 - x1) + abs(y2 - y1))
using namespace std;

int n, m, answer = 1000000000;
int graph[65][65];
bool visited[65][65];
vector<pair<int, int>> chickens;
vector<pair<int, int>> arr;
vector<pair<int, int>> houses;

void input() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 2)    chickens.push_back({i, j});
            else if(graph[i][j] == 1)    houses.push_back({i, j});
        }
    }
}

void solution() {
    int sum = 0;
    
    for(int i = 0; i < houses.size(); i++) {
        int min = 1000000000;
        for(int j = 0; j < arr.size(); j++) {
            int value = DISTANCE(houses[i].first, houses[i].second, arr[j].first, arr[j].second);

            if(min > value) {
                min = value;
            }
            
        }
        sum += min;
    }

    if(answer > sum)    answer = sum;
}

void combi() {
    int size = chickens.size();
    vector<bool> temp(size, false);

    for(int i = 0; i < m; i++) {
        temp[i] = true;
    }

    sort(temp.begin(), temp.end());

    do
    {
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i])
                arr.push_back({chickens[i].first, chickens[i].second});
        }

        solution();
        arr.clear();

    } while (next_permutation(temp.begin(), temp.end()));
    

}

int main() {
    input();
    combi();
    cout << answer;

}