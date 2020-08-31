#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#define DISTANCE(x1, y1, x2, y2)    abs(x1 - x2) + abs(y1 - y2)
using namespace std;

string hand;
int location[10][2] = {
    {3, 1},
    {0, 0}, {0, 1}, {0, 2},
    {1, 0}, {1, 1}, {1, 2},
    {2, 0}, {2, 1}, {2, 2}
};
int leftX = 3, leftY = 0, rightX = 3, rightY = 2, currentX, currentY;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    for(int i = 0; i < numbers.size(); i++) {

        int current_num = numbers[i];
        currentX = location[current_num][0];
        currentY = location[current_num][1];

        if (current_num == 1 || current_num == 4 || current_num == 7) {
            answer += "L";
            leftX = currentX;
            leftY = currentY;
        } else if (current_num == 3 || current_num == 6 || current_num == 9) {
            answer += "R";
            rightX = currentX;
            rightY = currentY;
        } else {
            int d1 = DISTANCE(leftX, leftY, currentX, currentY);
            int d2 = DISTANCE(rightX, rightY, currentX, currentY);

            if(d1 > d2) {
                answer += "R";
                rightX = currentX;
                rightY = currentY;
            } else if (d1 < d2) {
                answer += "L";
                leftX = currentX;
                leftY = currentY;
            } else {

                if(hand == "right") {
                    answer += "R";
                    rightX = currentX;
                    rightY = currentY;
                } else {
                    answer += "L";
                    leftX = currentX;
                    leftY = currentY;
                }
            }
        }
    }


    return answer;
}