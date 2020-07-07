#include <iostream>
#include <string>
using namespace std;

void solution(int num);

int N;

int main() {
    int input;
    cin >> input;
    solution(input);
}

void solution(int num) {
    int count = 0;

    /*종료 조건 => 1보다 작거나 주어진 수 보다 큰 수*/
    if(num < 1) {
        return ;
    }

    /*주어진 수가 1의자리 혹은 10의 자리 인 경우 모두 등차수열임
    100의 자리 부터 판단하면 됨*/
    
    if(num < 100) {
        count = num;
        cout << count;
        return ;
    } else {
        count = 99;

        
        for(int i = 100; i <= num; i++) {
            string number = to_string(i);
            int criteria = (number[0] - '0') - (number[1] - '0');
            int current;
            int type = -1;
            for(int j = 1; j < number.size(); j++) {
                current = (number[j-1] - '0') - (number[j] - '0');

                if(current != criteria) {
                    type = 0;
                    break;
                } else {
                    type = 1;
                }
            }

            if(type == 0 || type == -1) {
                continue;
            } else if( type == 1 ) {
                count++;
            }

            type = -1;

        }

    }

    cout << count;
    return ;
}