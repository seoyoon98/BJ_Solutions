#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

//1<=N<=1000 / 1<=M<=10000
int N, M, X;

vector<pair<int, int> > graph[10001];
int d[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, start));
    d[start] = 0;

    while(!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;

            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &N, &M, &X);

    for (int i = 0; i < M; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        graph[start].push_back(make_pair(end, cost));
    }

    fill(d, d + 1001, INF);

    dijkstra(X);

    vector<int> toParty = vector<int>(d, d + N + 1); // X에서 각 도시로 가는 최단 시간을 저장

    int maxTime = 0;

    for (int i = 1; i <= N; i++) {
        fill(d, d + 1001, INF);
        dijkstra(i);
        int totalTime = toParty[i] + d[X];  // 왕복 시간을 계산
        maxTime = max(maxTime, totalTime);  // 가장 긴 왕복 시간을 찾음
    }

    printf("%d\n", maxTime);  // 가장 오래 걸리는 학생의 왕복 시간 출력

    return 0;
}