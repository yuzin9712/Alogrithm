#include <iostream>
#include <math.h>
using namespace std;

int solution(int n);

int main() {
    int n, answer;

    while(1) {

        cin >> n;

        if(n == 0) {
            break;
        }

        answer = solution(n);
        cout << answer << "\n";

    }
}

int solution(int n) {

    int left, right, count = 0;

    left = n;
    right = 2*n;

    for(int i = left + 1; i <= right; i++) {

        for(int j = 2; j <= sqrt(i); j++) {
            
        if(i % j == 0) {
            break;
        }
        count++;

        }
        
    }

    return count;
    
}