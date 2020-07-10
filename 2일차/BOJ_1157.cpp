#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string word;
    vector <int> arr(26,0);

    cin >> word;

    for(int i = 0; i < word.size(); i++) {
        
        if(word[i] >= 'a' && word[i] <= 'z') {
            arr[word[i]-'a']++;

        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            arr[word[i]-'A']++;
        }
    }

    int max = *max_element(arr.begin(), arr.end());
    int maxnum = 0;
    int index;

    for(int j = 0; j < arr.size(); j++) {
        if(arr[j] == max) {
            index = j;
            maxnum++;
            if(maxnum > 1) {
                cout << "?";
                return 0;
            }
        }
    }

    cout << (char)(index + 'A');
    return 0;
}