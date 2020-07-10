#include <iostream>
#include <math.h>
using namespace std;

bool check(int num);

int main() {
    int n;
    int answer = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if(num == 1) {
            continue;
        } else {
            bool type = check(num);

            if(type) {
                answer++;
            }
        }
    }

    cout << answer;

}

/*sqrt(num)까지만 확인해도 된다는 수학적 정의확인했음!!!*/
bool check(int num) {
    for(int i = 2; i <= sqrt(num); i++) {
        if(num%i == 0) {
            return false;
        }
    }

    return true;
}