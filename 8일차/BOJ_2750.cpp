#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> arr;
    int size;
    int num;

    cin >> size;

    for(int i = 0; i < size; i++) {
        cin >> num;

        arr.push_back(num);
    }

    for(int j = 0; j < size; j++) {
        for(int k = 0; k < size; k++) {
            if(arr[j] < arr[k]) {
                int temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
    }

    for(int m = 0; m < size; m++) {
        cout << arr[m] << "\n";
    }
}