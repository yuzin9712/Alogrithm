#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void push(int num);
void pop();
void getSize();
void checkEmpty();
void getTop();

int top = -1;
vector <int> stack(10000, 0);

int main() {
    int n, num;
    string command;


    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
        
        getline(cin, command);
        string buf;
        stringstream ss(command);
        ss >> buf;

        if(buf == "push") {
            ss >> buf;

            int num = stoi(buf);
            push(num);

        } else if (buf == "pop") {
            pop();
        } else if (buf == "top") {
            getTop();
        } else if (buf == "size") {
            getSize();
        } else if (buf == "empty") {
            checkEmpty();
        }
    }
    
}

void push(int num) {
    top++;
    stack[top] = num;
    return ;
}

void pop() {
    if(top == -1) {
        cout << -1 << "\n";
    } else {
        cout << stack[top] << "\n";
        top--;
    }
    return ;
}

void getSize() {
    cout << top + 1 << "\n";
    return ;
}

void checkEmpty() {
    if(top == -1) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
    return ;
}

void getTop() {
    if(top == -1) {
        cout << -1 << "\n";
    } else {
        cout << stack[top] << "\n";
    }
    return ;
}