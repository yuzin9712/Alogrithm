#include <iostream>
#include <vector>
using namespace std;

void checkSelfNumber(int num);

vector <int> check(10001);

int main() {

    checkSelfNumber(1);

    for(int i = 1; i < check.size(); i++) {
        if(check[i] == 0) {
            cout << i << "\n";
        }
    }

}

/*배열 범위 주의 런타임 에러!*/
void checkSelfNumber(int num) {
    /* 종료 조건 구하기 => 10000 보다 큰 수 */
    if(num > 10000) {
        return ;
    }
    string number = to_string(num);
    int sum = num;

    for(int i = 0; i < number.size(); i++) {
        sum = sum + (number[i] - '0'); //만들어진 수
    }

    if(sum > 10000) {
        checkSelfNumber(num+1);
    } else {
        check[sum] = 1;
        checkSelfNumber(num+1);   
    }
}

