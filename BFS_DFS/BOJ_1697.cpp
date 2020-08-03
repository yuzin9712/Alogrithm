#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int visited[100010];
int moves[3] = {-1, 1, 2};

void BFS(int n, int k) {
    q.push(n);
    visited[n] = 1;

    while(!q.empty()) {
        int pos = q.front();
        q.pop();

        // cout << "pos : " << pos << " value : " << visited[pos] << "\n";

        if(pos == k) {
            break;
        }

        for(int i = 0; i < 3; i++) {
            /*if 문 순서로 인해 런타임 에러가 계속 발생했다. 먼저 범위를 체크한다음에 방문여부를 따져야하는데 반대로해서 계속 오류가 났다.*/
            if(i != 2 && pos + moves[i] >= 0 && pos + moves[i] <= 100000  && visited[pos + moves[i]] == 0) {
                q.push(pos + moves[i]);
                visited[pos + moves[i]] = visited[pos] + 1;
            } else if (i == 2 && pos * moves[i] >= 0 && pos * moves[i] <= 100000 && visited[pos * moves[i]] == 0) {
                q.push(pos * moves[i]);
                visited[pos * moves[i]] = visited[pos] + 1;
            }
        }
    }
}

int main() {
    int n, k;

    cin >> n >> k;

    BFS(n, k);

    cout << visited[k] - 1;
}