#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 1001
#define INF 1e9

using namespace std;

int n, m, k;
// 1<=n<=1000, 0<=m<=2000000, 1<=k<=100

priority_queue<int> heap[1001]; // 내림차순(top이 제일 큰 값)

void dijkstra(int n, vector<pair<int, int> >graph[], int start) {
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, start));
    heap[start].push(0);

    while(!pq.empty()) {
        int d = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int cost = d + graph[now][i].second;
            int next = graph[now][i].first;

            if (heap[next].size() < k) {
                heap[next].push(cost);
                pq.push(make_pair(-cost, next));
            }
            else {
                if (cost < heap[next].top()) {
                    heap[next].pop();
                    heap[next].push(cost);
                    pq.push(make_pair(-cost, next));
                }
            }
        }
    }
}

int main( ){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    vector<pair<int, int> > graph[n];

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from - 1].push_back(make_pair(to - 1, cost));
    }

    dijkstra(n, graph, 0);

    for(int i = 0; i < n; i++){
        if(heap[i].size() < k){
            cout << -1 << "\n";
        }
        else {
            cout << heap[i].top() << "\n";
        }
    }

    return 0;
}
