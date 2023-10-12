#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define MAX 501

int board[MAX][MAX], visited[MAX][MAX];
int N, M, pic_num, max_pic;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void BFS(pair<int, int> point) {
    queue<pair<int, int> > q;
    visited[point.X][point.Y] = 1;
    q.push(point);
    int pop_cnt = 0;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        pop_cnt++;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visited[nx][ny] == 1 || board[nx][ny] != 1) continue;
            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }

    max_pic = max(max_pic, pop_cnt);
}

void Init() {
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) 
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];

    pic_num = 0;
    max_pic = 0;
}

void PrintResult() {
    cout << pic_num << '\n' << max_pic << '\n';
}

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (board[i][j] != 1 || visited[i][j] == 1) continue;
            pic_num++;
            BFS(make_pair(i, j));
        }
    }

    PrintResult();

    return 0;
}