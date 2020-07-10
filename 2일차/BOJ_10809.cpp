#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string word;
    vector <int> arr(26,-1);

    getline(cin, word);

    for(int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        arr[index] = word.find_first_of(word[i]);
    }

    for(int j = 0; j < arr.size(); j++) {
        cout << arr[j] << " ";
    }
}