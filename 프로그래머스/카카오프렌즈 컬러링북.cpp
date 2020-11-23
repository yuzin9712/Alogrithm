#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int moves[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};
int visited[110][110];

queue<pair<int, int>> q;

int BFS(int x, int y, int m, int n, vector<vector<int>> picture) {
    int size = 1;
    int color = picture[x][y];
    q.push({x, y});
    visited[x][y] = 1;
    
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];
            
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && picture[nx][ny] == color && visited[nx][ny] == 0) {
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
                size++;
            }
        }
    }
    
    return size;
    
}

void init() {
    while(!q.empty()) {
        q.pop();
    }

    for(int i = 0; i < 110; i++) {
        for(int j = 0; j < 110; j++) {
            visited[i][j] = 0;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    init();
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && visited[i][j] == 0) {
                number_of_area++;
                int result = BFS(i, j, m, n, picture);

                if(result > max_size_of_one_area) {
                    max_size_of_one_area = result;
                }
            }
        }
    }
    
    cout << number_of_area << " " << max_size_of_one_area << "\n";
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    int m, n, color;
    cin >> m >> n;
    vector<vector<int>> picture(m);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> color;
            picture[i].push_back(color);
        }
    }


    solution(m, n, picture);
}