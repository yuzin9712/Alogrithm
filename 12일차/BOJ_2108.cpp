#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


int main() {
    int n, num, max = 0;
    vector <int> arr;
    vector <int> frequency(8001,0);

    scanf("%d", &n);

    for(int i = 0; i < n ; i++) {
        scanf("%d", &num);
        arr.push_back(num);
        frequency[num+4000]++;
    }

    sort(arr.begin(), arr.end());
    
    /*산술평균*/
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    printf("%.0f\n",round(sum/(double)n));
    /*중앙값*/
    if(n == 1) {
        printf("%d\n", num);
    } else {
        printf("%d\n", arr[n/2]);
    }


    /*최빈값*/
    int x = 0;
    int answer;
    max = *max_element(frequency.begin(), frequency.end());
    for(int i = 0; i < frequency.size(); i++) {
        if(frequency[i] == max && x == 0) {
            x++;
            answer = i-4000;
        } else if(frequency[i] == max && x == 1) {
            answer = i-4000;
            break;
        }
    }

    printf("%d\n", answer);

    /*범위*/
    if(n == 1) {
        printf("0");
    } else {
        printf("%d",arr[n-1]-arr[0]);
    }

}