#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, answer = 1000000000;
int graph[35][35];
int copygraph[35][35];
vector<int> cnt(6, 0);


void input() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
}

void makeRect() {

    int points[2][2];
    
    for(int i = 1; i <= n; i++) {
        int count = 0;
        
        for(int j = 1; j <= n; j++) {

            if(copygraph[i][j] == 5) {
                count++;
                points[count - 1][0] = i;
                points[count - 1][1] = j;

                if(count == 2) {
                    for(int l = points[0][1] + 1; l < points[1][1]; l++) {
                        if(copygraph[i][l] != 5) {
                            copygraph[i][l] = 5;
                        }
                    }
                }
            }
            
        }
    }
}

void getline(int x, int y, int d1, int d2) {
    int nx = x, ny = y;

    while(nx >= 1 && nx <= n && ny >= 1 && ny <= n && nx <= x + d1 && ny >= y - d1) {
        copygraph[nx][ny] = 5;
        nx++;
        ny--;
    }

    nx = x, ny = y;

    while(nx >= 1 && nx <= n && ny >= 1 && ny <= n && nx <= x + d2 && ny <= y + d2) {
        copygraph[nx][ny] = 5;
        nx++;
        ny++;
    }

    nx = x + d1, ny = y - d1;

    while(nx >= 1 && nx <= n && ny >= 1 && ny <= n && nx <= x + d1 + d2 && ny <= y - d1 + d2) {
        copygraph[nx][ny] = 5;
        nx++;
        ny++;
    }

    nx = x + d2, ny = y + d2;

    while(nx >= 1 && nx <= n && ny >= 1 && ny <= n && nx <= x + d2 + d1 && ny >= y + d2 - d1) {
        copygraph[nx][ny] = 5;
        nx++;
        ny--;
    }

    makeRect();
}

void makegroup(int x, int y, int d1, int d2) {

    for(int i = 1; i < x + d1; i++) {
        for(int j = 1; j <= y; j++) {
            if(copygraph[i][j] != 5) {
                copygraph[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= x + d2; i++) {
        for(int j = y + 1; j <= n; j++) {
            if(copygraph[i][j] != 5) {
                copygraph[i][j] = 2;
            }
        }
    }

    for(int i = x + d1; i <= n; i++) {
        for(int j = 1; j < y - d1 + d2; j++) {
            if(copygraph[i][j] != 5) {
                copygraph[i][j] = 3;
            }
        }
    }

    for(int i = x + d2 + 1; i <= n; i++) {
        for(int j = y - d1 + d2; j <= n; j++) {
            if(copygraph[i][j] != 5) {
                copygraph[i][j] = 4;
            }
        }
    }
}

void solution(int x, int y, int d1, int d2) {
    int max, min;
    
    getline(x, y, d1, d2);
    makegroup(x, y, d1, d2);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cnt[copygraph[i][j]] += graph[i][j];
        }
    }
    
    max = *max_element(cnt.begin() + 1, cnt.end());
    min = *min_element(cnt.begin() + 1, cnt.end());

    if(answer > max - min)
        answer = max - min;
}

void init() {
    memset(copygraph, 0, sizeof(copygraph));
    
    for(int i = 0; i < cnt.size(); i++) {
        cnt[i] = 0;
    }
}

void selectPointDistance() {
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y++) {
            for(int d1 = 1; d1 <= n; d1++) {
                for(int d2 = 1; d2 <= n; d2++) {
                    if(x < x + d1 + d2 && x + d1 + d2 <= n && y - d1 >= 1 && y - d1 < y && y < y + d2 && y + d2 <= n) {
                        solution(x, y, d1, d2);
                        init();
                    }
                }
            }
        }
    }
}

int main() {
    input();
    selectPointDistance();
    cout << answer;

}