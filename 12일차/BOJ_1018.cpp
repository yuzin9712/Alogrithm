#include <iostream>
#include <vector>
#include <string>
using namespace std;

void check_W(int x, int y);
void check_B(int x, int y);

int m, n;
int answer = 9999999;

vector <vector <char>> arr(50,vector<char>(50));
vector <vector <char>> comp1 {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};

vector <vector <char>> comp2 {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
};

int main() {

    char color;

    cin >> m >> n;
    cin.ignore();

    for(int i = 0; i < m; i++ ) {
        for(int j = 0; j < n; j++) {
            cin >> color;
            arr[i][j] = color;
        }
    }


    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            check_W(i, j);
            check_B(i, j);
        }
    }


    cout << answer;
}

void check_W(int x, int y) {
    int val = 0;

    if(x + 8 <= m && y + 8 <= n) {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(comp1[i][j] != arr[i+x][j+y]) {
                    val++;
                }
            }
        }
        if(answer > val) {
            answer = val;
        }
    }
    return ;
}

void check_B(int x, int y) {
    int val = 0;

    if(x + 8 <= m && y + 8 <= n) {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(comp2[i][j] != arr[i+x][j+y]) {
                    val++;
                }
            }
        }
        if(answer > val) {
            answer = val;
        }
    }
    return ;
}