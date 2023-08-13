#include <iostream>
#include <queue>

#define MAX 200001

using namespace std;

// 1<=m<=200000, m-1<=n<=200000
int house_num, road_num, start_h, end_h, len, total;
int visited[MAX];
int ans;
vector<int> ans_vec;

class Edge {
    public:
        int node;
        int distance;
        Edge(int node, int distance) {
            this->node = node;
            this->distance = distance;
        }

        bool operator<(const Edge &edge) const {
            return this->distance > edge.distance;
        }
};

vector<Edge> graph[MAX];

void value_input() {
    for (int i = 1; i <= road_num; i++) {
        scanf("%d %d %d", &start_h, &end_h, &len);
        graph[start_h].push_back(Edge(end_h, len));
        graph[end_h].push_back(Edge(start_h, len));
        total += len;
    }
}

void prim()  {
    priority_queue<Edge> pq;

    pq.push(Edge(0, 0));

    while(!pq.empty()) {
        Edge temp = pq.top();
        pq.pop();

        int end = temp.node;
        int cost = temp.distance;

        if (visited[end] == 0) {
            visited[end] = 1;
            ans += cost;
            //printf("end: %d, cost: %d, ans: %d\n", end, cost, ans);
            for (int i = 0; i < graph[end].size(); i++)
                pq.push(Edge(graph[end][i].node, graph[end][i].distance));
        }
    }

    ans = total - ans;
    ans_vec.push_back(ans);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1) {
        scanf("%d %d", &house_num, &road_num);

        if (house_num == 0 && road_num == 0)
            break;

        fill_n(visited, MAX, 0);
        for (int i = 0; i < MAX; i++)
            graph[i].clear();

        ans = 0;
        total = 0;

        value_input();
        prim();
    }

    for (int result : ans_vec)
        printf("%d\n", result);

    return 0;
}