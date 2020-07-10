#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*2차원 - arr[6][5]*/
    vector <vector <int>> arr(15,vector<int>(15,0));

    for(int i = 0; i < 15; i++) { /*층*/

        for(int j = 0; j < 15; j++) { /*호*/
            if(i == 0) {
                arr[i][j] = j;
            } else {
                for(int k = 1; k <= j; k++) {
                    arr[i][j] = arr[i][j] + arr[i-1][k];
                }
            }
        }
    }

    int testnum, k, n;

    cin >> testnum;

    for(int i = 0; i < testnum; i++) {
        cin >> k;
        cin >> n;

        cout << arr[k][n] << "\n";
    }
     
}