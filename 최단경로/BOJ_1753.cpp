#include <iostream>
#include <utility>
#include <queue>
#include <vector>
/*11로 두면 x
왜 ????????
*/
#define INF 1000000000

using namespace std;

vector<pair<int, int>> graph[20010];
int d[20010];
int V, E, K, u, v, w;

void init() {
    for(int i = 1; i <= V; i++) {
        d[i] = INF;
    }
}

void input() {
    cin >> V >> E >> K;

    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v, w));
    }
}

void dijkstra(int v) {
    priority_queue <pair<int, int>> pq;

    d[v] = 0;
    pq.push(make_pair(0, v));

    while(!pq.empty()) {
        int current_vertex = pq.top().second;
        int current_distance = -pq.top().first;

        pq.pop();

        /*???????*/
        // if(d[current_vertex] < current_distance)    continue;

        for(int i = 0; i < graph[current_vertex].size(); i++) {
            int next_vertex = graph[current_vertex][i].first;
            int next_distance = current_distance + graph[current_vertex][i].second;

            if(d[next_vertex] > next_distance) {
                d[next_vertex] = next_distance;
                pq.push(make_pair(-next_distance, next_vertex));
            }
        }

    }

}

int main() {
    input();

    init();

    dijkstra(K);

    for(int i = 1; i <= V; i++) {
        if(d[i] == INF) cout << "INF\n";
        else            cout << d[i] << "\n";
    }
}