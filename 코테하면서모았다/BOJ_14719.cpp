#include <iostream>
#define MIN(a, b) a < b ? a : b
using namespace std;

int h, w;
int block[500];
int sum;

void input() {
    cin >> h >> w;

    for(int i = 0; i < w; i++) {
        cin >> block[i];
    }
}

void solution() {
    for(int i = 1; i < w - 1; i++) {
        int leftMax = -1, rightMax = -1;

        for(int left = i - 1; left >= 0; left--) {
            if(leftMax < block[left]) {
                leftMax = block[left];
            }
        }

        for(int right = i + 1; right < w; right++) {
            if(rightMax < block[right]) {
                rightMax = block[right];
            }
        }
        int value = MIN(leftMax, rightMax);

        if(block[i] < value) {
            // cout << value - block[i] << " ";
            sum += (value - block[i]);
        }
        
    }
}

int main() {

    input();
    solution();
    cout << sum;
}