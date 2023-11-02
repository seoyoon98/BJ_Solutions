#include <iostream>
#include <queue>
#include <algorithm>
#include <initializer_list>

using namespace std;

#define MAX_N 100001

int dist[MAX_N];
int N, K;

void Init() {
    cin >> N >> K;
    fill(dist, dist + MAX_N - 1, -1);
    dist[N] = 0;
}

void BFS() {
    queue<int> q;
    q.push(N);

    while(dist[K] == -1) {
        int cur = q.front(); q.pop();
        for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (dist[nxt] != -1) continue;

            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    cout << dist[K] << '\n';
}

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();

    BFS();

    return 0;
}