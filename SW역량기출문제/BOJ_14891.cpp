#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
using namespace std;

int k, wheelNum, rotation, arr[5], answer = 0;
vector<bitset<8>> wheel(5);
bitset<8> bits;


void solution() {
    /*전*/
    for(int i = wheelNum - 1; i >= 1; i--) {
        if(arr[i + 1] == -1) {
            if(wheel[i + 1][1] == wheel[i][5]) {
                arr[i] = 0;
            } else {
                arr[i] = 1;
            }
        } else if (arr[i + 1] == 0) {
            arr[i] = 0;
        } else {
            if(wheel[i + 1][1] == wheel[i][5]) {
                arr[i] = 0;
            } else {
                arr[i] = -1;
            }
        }
    }

    /*후*/

    for(int i = wheelNum + 1; i <= 4; i++) {
        if(arr[i - 1] == -1) {
            if(wheel[i - 1][5] == wheel[i][1]) {
                arr[i] = 0;
            } else {
                arr[i] = 1;
            }
        } else if (arr[i - 1] == 0) {
            arr[i] = 0;
        } else {
            if(wheel[i - 1][5] == wheel[i][1]) {
                arr[i] = 0;
            } else {
                arr[i] = -1;
            }
        }
    }

    // for(int i = 1; i <= 4; i ++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
}

void shift() {

    for(int i = 1; i <= 4; i++) {
        /*시계방향*/
        bool type = false;

        if(arr[i] == 1) {

            type = (wheel[i][0] == 1) ? true : false;

            wheel[i] = wheel[i] >> 1;

            if(type)    wheel[i][7] = 1;
            
        } else if (arr[i] == -1) {

            type = (wheel[i][7] == 1) ? true : false;

            wheel[i] = wheel[i] << 1;

            if(type)    wheel[i][0] = 1;
        }
    }

    // for(int i = 1; i <= 4; i++) {
    //     for(int j = 7; j >= 0; j--) {
    //     cout << wheel[i][j];
    //     }
    //     cout << "\n";
    // }
    
}

void getScore() {
    for(int i = 1; i <= 4; i++) {
        if(wheel[i][7] == 1) {
            if(i == 1)  answer += 1;
            else if(i == 2) answer += 2;
            else if(i == 3) answer += 4;
            else            answer += 8;
        }
    }
}

void input() {
    for(int i = 0; i < 4; i++) {
        cin >> bits;
        wheel[i + 1] = bits;
    }

    cin >> k;

    for(int i = 0; i < k; i++) {
        
        cin >> wheelNum >> rotation;
        arr[wheelNum] = rotation;


        /*바로계산*/
        solution();
        shift();

        memset(arr, 0, sizeof(arr));
    
    }

    getScore();

    cout << answer;


}

int main() {

    input();

}