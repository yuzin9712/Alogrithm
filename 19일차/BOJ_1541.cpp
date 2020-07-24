#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    int flag = 0, answer = 0;

    getline(cin, line);

    for(int i = 0; i < line.size(); i++) {

        if(line[i] == '-') {
            flag = 1;
        }

        if(flag == 1 && line[i] == '+') {
            line[i] = '-';
            flag = 0;
        }
        
    }

    cout << line;

}