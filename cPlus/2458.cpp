#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 501

int N, M;
// 2<=N<=500, 0<=M<=N(N-1)/2
int cnt, answer;

bool visited[MAX];

vector<vector<int> > taller(MAX);
vector<vector<int> > shorter(MAX);

void dfs(vector<vector<int> > &graph, int index) {
    if (visited[index]) return;

    visited[index] = true;

    for (int i = 0; i < graph[index].size(); i++) {
        int next = graph[index][i];

        if (!visited[next]) {
            cnt++;
            dfs(graph, next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    taller.resize(N);
    shorter.resize(N);

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        taller[from].push_back(to);
        shorter[to].push_back(from);
    }

    cnt = 0, answer = 0;

    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        dfs(taller, i);
        fill(visited, visited + MAX, false);
        dfs(shorter, i);

        if (cnt == N - 1) answer++;
        cnt = 0;
    }

    cout << answer << "\n";

    return 0;
}