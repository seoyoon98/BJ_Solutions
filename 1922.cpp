#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000

using namespace std;

int N, M;
// 1 <= N <= 1000, 1 <= M <= 100000

int parent[MAX + 1];

class Edge {
    public:
        int node[2];
        int distance;

        Edge(int a, int b, int distance) {
            this->node[0] = a;
            this->node[1] = b;
            this->distance = distance;
        }

        bool operator<(const Edge &edge) const {
            return this->distance < edge.distance;
        }
};

int Find(int node) {
    if(parent[node] == node) return node;
    else return Find(parent[node]);
}

void Union(int node1, int node2) {
    node1 = Find(node1);
    node2 = Find(node2);
    parent[node1] = node2;
}

bool isCycle(int node1, int node2) {
    node1 = Find(node1);
    node2 = Find(node2);
    if (node1 == node2) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<Edge> graph;

    for (int i = 0; i < M; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph.push_back(Edge(v1, v2, w));
    }

    sort(graph.begin(), graph.end());

    for (int i = 0; i < N; i++)
        parent[i] = i;

    int sum = 0;

    for (int i = 0; i < graph.size(); i++) {
        if (!isCycle(graph[i].node[0], graph[i].node[1])) {
            sum += graph[i].distance;
            Union(graph[i].node[0], graph[i].node[1]);
        }
    }

    cout << sum << "\n";

    return 0;
}