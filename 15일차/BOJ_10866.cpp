#include <iostream>
#include <string>
#include <deque>
#include <sstream>
using namespace std;

deque <int> dq;

int main() {

    int n, num;
    string command;

    cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++) {

        getline(cin, command);

        /*자꾸기억이안남*/
        string buf;
        stringstream ss(command);
        ss >> buf;

        /*""이거로 하면 맞고 ''이거로 하면 틀림 ???*/
        if(buf == "push_back") {
            ss >> buf;

            num = stoi(buf);
            dq.push_back(num);
            
        } else if( buf == "push_front") {
            ss >> buf;

            num = stoi(buf);
            dq.push_front(num);

        } else if (buf == "pop_front") {
            if(dq.empty()) {
                cout << -1 << "\n";
            } else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (buf == "pop_back") {
            if(dq.empty()) {
                cout << -1 << "\n";
            } else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (buf == "size") {
            cout << dq.size() << "\n";
        } else if (buf == "empty") {
            if(dq.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (buf == "front") {
            if(dq.empty()) {
                cout << -1 << "\n";
            } else {
                cout << dq.front() << "\n";
            }
        } else if (buf == "back") {
            if(dq.empty()) {
                cout << -1 << "\n";
            } else {
                cout << dq.back() << "\n";
            }
        }

    }

    

}