#include <iostream>
using namespace std;

int main() {
    int weight;

    cin >> weight;

    int div = weight/5;

    while(1) {
        if(div == -1) {
            cout << div;
            return 0;
        }
        
        if((weight-5*div)%3 == 0 && (weight-5*div) + 5*div == weight) {
            div = div + (weight-5*div)/3;
            cout << div;
            return 0;
        }
        div--;
    }
}