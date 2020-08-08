#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> channels;
int arrow;

void swap(string a, string b) {

}

int main() {
    string channel;
    int num;

    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> channel;
        channels.push_back(channel);
    }

    int i = 0;

    while(channels[0] != "KBS1") {
        cout << 3;
        string temp = channels[i];
        channels[i] = channels[i + 1];
        channels[i + 1] = temp;
        i++;
    }

    while(channels[1] != "KBS2") {
        cout << 2;
        i--;
    }
     
}