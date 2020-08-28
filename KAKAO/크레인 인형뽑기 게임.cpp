#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;

    for(int i = 0; i < moves.size(); i++) {
        int y = moves[i] - 1;

        for(int x = 0; x < board[y].size(); x++) {
            if(board[x][y] == 0)
                continue;

            else {
                if(!s.empty() && s.top() == board[x][y]) {
                    s.pop();
                    answer += 2;
                } else {
                    s.push(board[x][y]);
                }
            }

            board[x][y] = 0;
            break;
        }
    }
    
    return answer;

}