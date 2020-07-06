#include <iostream>
#include <string>
using namespace std;

int arr[10];

int main() {
    int a,b,c;
    int result;

    cin >> a >> b >> c;
    result = a * b * c;

    string str_result = to_string(result);

    for(int i = 0; i < str_result.size(); i++) {

        /*char to int*/
        arr[str_result[i] - '0']++;

    }

    for(int j = 0; j < 10; j++) {
        cout << arr[j] << "\n";
    }
    
}