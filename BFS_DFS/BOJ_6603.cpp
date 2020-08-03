#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visited[51];
int  numbers[51];
int k;

void DFS(int v, int cnt) {
    if(cnt == 6) { /*?*/
        for(int i = 0; i < k; i++) {
            if(visited[i] != 0) {
                cout << numbers[i] << " ";
            }
        }
        cout << "\n";
        return ;
    }

    if(k - v < 6 - cnt) {
        return ;
    } 

    visited[v] = 1;
    DFS(v+1, cnt + 1);
    visited[v] = 0;
    DFS(v+1, cnt);
    
}

int main() {
    int num;

    do
    {
        cin >> k;

        for(int i = 0 ; i < k; i++) {
            cin >> num;
            numbers[i] = num;
        }

        DFS(0, 0);
        cout << "\n";

        /*초기화해줄때사용*/
        memset(visited,0, sizeof(visited));
        memset(numbers,0, sizeof(numbers));

    } while (k != 0);


}