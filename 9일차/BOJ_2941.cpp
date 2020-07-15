#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    vector <string> word {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int answer = 0;
    int num;

    cin >> line;
    num = line.size();


    for(int i = 0; i < 8; i++) {
        string::size_type n;
        int size = word[i].size();

        while(1) {
            n = line.find(word[i]);
            if(n == string::npos) {
                // cout << "not found\n";
                break;
            } else {
                // cout << "found " << line.substr(n,size) << "\n";
                line.replace(n,size,"|");
                answer++;
            }
        }
        
    }

    for(int j = 0; j < line.size(); j++) {
        if(line[j] != '|') {
            answer++;
        }
    }

    cout << answer;

}