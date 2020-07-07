#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string line;
    int num;

    getline(cin, line);

    num = count(line.begin(), line.end(), ' ');

    if(*line.begin() == ' ') {
        num--;
    }
    if(*(line.end()-1) == ' ') {
        num--;
    }
    cout << num + 1;


}