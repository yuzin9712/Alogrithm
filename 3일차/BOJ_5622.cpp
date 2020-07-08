#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    int sum = 0;
    vector <int> time{3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};

    cin >> line;

    for(int i = 0; i < line.size(); i++) {
        sum = sum + time[line[i]-'A']; 
    }

    cout << sum;
}