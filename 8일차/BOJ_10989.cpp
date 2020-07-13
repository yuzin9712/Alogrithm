#include <cstdio>
#include <vector>
using namespace std;

int main() {
    vector <int> arr(10001,0);

    int size, num;

    scanf("%d",&size);

    for(int i = 0; i < size; i++) {
        scanf("%d",&num);
        arr[num]++;
    }

    for(int j = 1; j < arr.size(); j++) {
        if(arr[j] == 0) {
            continue;
        } else {
            printf("%d\n",j);
            arr[j] --;
            j--;
        }
    }

}