#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    double sum = 0.0;
    double score;
    vector <double> score_arr;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> score;

        score_arr.push_back(score);
    
    }

    /*vector에서 최대 값 구하기*/
    int max = *max_element(score_arr.begin(), score_arr.end());

    for(int j = 0; j < n; j++) {
        
        score_arr[j] = (double)score_arr[j]/max*100;
        sum = sum + score_arr[j];
        
    }

    cout << (double)sum/n;

}