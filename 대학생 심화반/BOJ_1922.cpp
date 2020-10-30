#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge{
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }

    /* < less than > greater than*/

    /*
    edge1.operator<(edge2) 로 변함
    edge1에 대해서 edge2와 비교했을 때 ,, edge2가 작으면 true 아니면 false 반환!
    오름차순으로 정렬하게 됨 : )
    */
    bool operator <(Edge &edge) {
        return this->distance < edge.distance;
    }

};

int n, m;
int sum = 0;
int edgeNum;
int parent[1001];
vector<Edge> graph;

void init() {

    /*부모 노드를 자기 자신으로 초기화 했음*/
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

void input() {
    int a, b, c;

    cin >> n >> m;

    init();

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        graph.push_back(Edge(a - 1, b - 1, c));
    }

    sort(graph.begin(), graph.end());

    // for(int i = 0; i < m; i++) {
    //     cout << graph[i].node[0] << " " << graph[i].node[1] << " " << graph[i].distance << "\n";
    // }
}

/*vertex의 부모 vertex가 무엇인가? 재귀로 찾아버리기!
재귀가 끝나는 조건은? 주어진 vertex와 그것의 부모 vertex가 같을때 -> 자기 자신이 부모일 때! 더이상 올라갈 곳이 없으니까 끝!*/
int getParent(int vertex) {
    if(vertex == parent[vertex]) {
        return vertex;
    }
    return parent[vertex] = getParent(parent[vertex]);
}

/*cycle이 안 생기는 걸 확인했으면, 숫자가 더 작은 부모로 합친다!*/
void unionParent(int vertex1, int vertex2) {
    int parent1 = getParent(vertex1);
    int parent2 = getParent(vertex2);

    /*부모 노드의 parent 값이 바뀌어야, 그 아래에 속한
    모든 노드들의 parent 값이 바뀌게 된다!*/
    if(parent1 < parent2) {
        parent[parent2] = parent1;
    } else {
        parent[parent1] = parent2;
    }
}

/*사이클이 생기는지 찾는다! 두 vertex의 parent가 같으면 cycle이 생김!*/
bool isMakeCycle(int vertex1, int vertex2) {
    int parent1 = getParent(vertex1);
    int parent2 = getParent(vertex2);

    if(parent1 == parent2) {
        return true;
    }
    return false;
}

void Kruskal() {

    /*정점 수 - 1 개의 edge가 뽑혀야 함*/
    int i = 0;

    while(edgeNum != n - 1) {
        // for(int i = 0; i < n; i++) {
        //     cout << "(" << i + 1 << ", " << parent[i] + 1 << ") ";
        // }
        // cout << "\n\n";
        if(!isMakeCycle(graph[i].node[0], graph[i].node[1])) {
            edgeNum++;
            sum += graph[i].distance;
            unionParent(graph[i].node[0], graph[i].node[1]);
        }
        i++;
    } 

}

int main() {
    input();
    Kruskal();
    cout << sum;
}