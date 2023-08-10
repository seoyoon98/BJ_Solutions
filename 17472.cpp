#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 11
#define MAX_ISLAND 7

using namespace std;

// 1<=N,M<=10
int N, M, MAP[MAX_SIZE][MAX_SIZE];

// DFS
bool visited[MAX_SIZE][MAX_SIZE];

// Union-Find
int parent[MAX_ISLAND];

// 상하좌우 x,y 좌표화 DFS에서 쓰임
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// 각 섬의 최대, 최소 x, y 좌표 (0: 최소 x / 1: 최대 x / 2: 최소 y / 3: 최대 y)
int island_coor[MAX_ISLAND][4]; 

// 섬 번호(노드 작업화를 위해)
int island_num;

// 답
int ans;

class Edge{
    public:
        int node[2];
        int distance;
        Edge(int start, int end, int distance) {
            this->node[0] = start;
            this->node[1] = end;
            this->distance = distance;
        }

        bool operator<(const Edge &edge) const {
            return this->distance < edge.distance;
        }
};

vector<Edge> graph;

void DFS(int x, int y) {
    if (visited[x][y]) return;

    visited[x][y] = true;
    MAP[x][y] = island_num;

    for (int i = 0; i < 4; i++) {
        switch (i)
        {
            case 0:
                if (island_coor[island_num][0] == 0)
                    island_coor[island_num][0] = x;
                else
                    island_coor[island_num][0] = min(island_coor[island_num][0], x);
                break;
        
            case 1:
                island_coor[island_num][1] = max(island_coor[island_num][1], x);
                break;
            
            case 2:
                if (island_coor[island_num][2] == 0)
                    island_coor[island_num][2] = y;
                else
                    island_coor[island_num][2] = min(island_coor[island_num][2], y);
                break;
        
            case 3:
                island_coor[island_num][3] = max(island_coor[island_num][3], y);
                break;
        }
    }

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M) {
            if (MAP[next_x][next_y] != 0 && !visited[next_x][next_y])
                DFS(next_x, next_y);
        }
    }
}

void distance(int now, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int now_x = x, now_y = y, dist = 0;

        while(1) {
            now_x += dx[i], now_y += dy[i];

            if (now_x < 1 || now_x > N || now_y < 1 || now_y > M || MAP[now_x][now_y] == now)
                break;
            
            if (MAP[now_x][now_y] == 0)
                dist++;
            else {
                graph.push_back(Edge(now, MAP[now_x][now_y], dist));
                break;
            }
        }
    }
}

int Find(int node) {
    if (parent[node] == node)
        return node;
    else
        return Find(parent[node]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[a] = b;
}

void kruskal() {
    sort(graph.begin(), graph.end());

    // Print edges in the graph
    cout << "\nAfter Sort:\n";
    for (Edge edge : graph) {
        cout << "From island " << edge.node[0] << " to island " << edge.node[1] << " with distance: " << edge.distance << "\n";
    }
    cout << "---------------------\n"; // For separation

    ans = 0;
    int cnt = 0;

    for (Edge edge : graph) {
        if (edge.distance <= 1) continue;

        // 싸이클이 생기지 않는 경우
        if (Find(edge.node[0]) != Find(edge.node[1])) {
            Union(edge.node[0], edge.node[1]);
            ans += edge.distance;
            cnt++;  // 추가된 간선의 수 증가
        }

        // 모든 섬들을 연결하는데 필요한 간선의 수는 '섬의 수 - 1'입니다.
        // 따라서 이를 만족하면 종료
        if (cnt == island_num - 1) break;
    }

    // 만약 연결된 간선의 수가 '섬의 수 - 1'보다 작으면 모든 섬을 연결하는 것이 불가능하다는 의미
    if (cnt != island_num - 1)
        ans = -1; // 또는 적절한 에러 메시지 출력

    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    // Union-Find
    for (int i = 1; i <= MAX_ISLAND; i++)
        parent[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> MAP[i][j];

    island_num = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (MAP[i][j] != 0) {
                if (!visited[i][j])
                    island_num++;
                
                DFS(i, j);
            }
        }
    }

    // ==========

    // 각 섬 번호 출력
    cout << "\nNew Map\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nMAX & MIN x, y\n";
    // 각 섬마다 최대 최소 x,y 좌표 출력
    for (int i = 1; i <= island_num; i++) {
        for (int j = 0; j < 4; j++) {
            cout << island_coor[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (MAP[i][j] != 0) 
                distance(MAP[i][j], i, j);
        }
    }

    // Print edges in the graph
    cout << "\nEdges in the graph:\n";
    for (Edge edge : graph) {
        cout << "From island " << edge.node[0] << " to island " << edge.node[1] << " with distance: " << edge.distance << "\n";
    }
    cout << "---------------------\n"; // For separation

    //

    kruskal();

    return 0;
}