#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    int answer;
    
    cin >> n;

    answer = n;

    for(int i = 0; i < n; i++) {
        string line;
        vector <int> arr(26,0);

        cin >> line;
        arr[line[0]-'a']++;
        for(int j = 1; j < line.size(); j++) {
            if(line[j-1] != line[j] && arr[line[j]-'a'] > 0) {
                answer--;
                break;
            }
            arr[line[j]-'a']++;

        }
    }

    cout << answer;
}