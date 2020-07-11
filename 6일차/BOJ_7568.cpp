#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x, y;
    /*2차원 - arr[50][2]*/
    vector <vector <int>> arr(50,vector<int>(2,0));
    vector <int> ranks;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;

        arr[i][0] = x;
        arr[i][1] = y;

    }

    for(int j = 0; j < n; j++) {
        int rank = 1;
        for(int k = 0; k < n; k++) {
            if((arr[j][0] < arr[k][0] && arr[j][1] < arr[k][1])) {
                rank++;
            }
        }
        ranks.push_back(rank);
    }

    for(int l = 0; l < n; l++) {
        cout << ranks[l] << " ";
    }
    
}