#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int n, m, answer = 1000000000;
vector<vector<int>> graph(10);
/*위 오 아 왼*/
int moves[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

vector<vector<bitset<4>>> directions = {
    {4, 2, 1, 8},
    {5, 10},
    {12, 6, 3, 9},
    {14, 7, 11, 13},
    {15}
};

vector<pair<int, int>> cctv;

void input() {
    int num;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> num;
            graph[i].push_back(num);
            if(graph[i][j] >= 1 && graph[i][j] <= 5)
                cctv.push_back({i, j});
        }
    }
}

void DFS(int index, vector<vector<int>> tempgraph) {
    vector<vector<int>> copygraph(10);

    if(index >= cctv.size()) {
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // cout << tempgraph[i][j] << " ";
                if(tempgraph[i][j] == 0)
                    count++;
            }
            // cout << "\n";
        }

        if(answer > count)
            answer = count;
        return ;
    }

    int x = cctv[index].first;
    int y = cctv[index].second;

    for(int i = 0; i < directions[tempgraph[x][y] - 1].size(); i++) {
        bitset<4> temp = directions[tempgraph[x][y] - 1][i];
        copygraph = tempgraph;
        // cout << temp << "\n";

        for(int j = 0; j < 4; j++) {

            int xx = x;
            int yy = y;

            if(temp[3 - j] == 1) {
                while(true) {
                    int nx = xx + moves[j][0];
                    int ny = yy+ moves[j][1];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && copygraph[nx][ny] != 6) {
                        if(copygraph[nx][ny] == 0)
                            copygraph[nx][ny] = 9;

                        xx = nx;
                        yy = ny;
                    } else {
                        break;
                    }
                }
            }
        }

        DFS(index + 1, copygraph);
    }
}


int main() {
    input();
    DFS(0, graph);
    cout << answer;
}