#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    bool graph[110];
    int t, n;

    cin >> t;

    for(int i = 0; i < t; i++) {
        int answer = 0;
        cin >> n;

        memset(graph, 1, sizeof(graph));

        for(int j = 2; j <= n; j++) {
            for(int k = 1; j * k <= n; k++) {
                graph[j * k] = !graph[j * k];
            }
        }

        for(int m = 1; m <= n; m++) {
            if(graph[m] == 1) {
                answer++;
            }
        }

        cout << answer << "\n";

    }

    
}