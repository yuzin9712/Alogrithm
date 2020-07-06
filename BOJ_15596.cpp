#include <iostream>
#include <vector>
using namespace std;

long long sum(std::vector<int> &a);

int main() {
    int input, num;
    vector <int> a;

    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> input;
        a.push_back(input);
    }

    sum(a);
}

long long sum(std::vector<int> &a) {
    /*
    a: 합을 구해야 하는 정수 n개가 저장되어 있는 배열 (0 ≤ a[i] ≤ 1,000,000, 1 ≤ n ≤ 3,000,000)
    리턴값: a에 포함되어 있는 정수 n개의 합
    */
   long long int ans = 0;

   for(int i = 0; i < a.size(); i++) {
       ans = ans + a[i];
   }

   return ans;
   
}