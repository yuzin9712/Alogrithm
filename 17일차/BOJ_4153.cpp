#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    long int x, y, z;
    vector <long int> arr(3);

    while(1) {

        cin >> arr[0] >> arr[1] >> arr[2];

        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
            break;
        } else {
            sort(arr.begin(), arr.end());

            long int a = arr[0]*arr[0] + arr[1]*arr[1];
            long int b = arr[2]*arr[2];

            if(a == b) {
                cout << "right\n";
            } else {
                cout << "wrong\n";
            }
        }
    }
}