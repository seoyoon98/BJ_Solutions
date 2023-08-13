#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 21

using namespace std;

// 2<=n<=20
int n, map[MAX][MAX], dist[MAX][MAX], shark_size, eat_cnt, ans;
pair<int, int> start;

queue<pair<int, int> > q;
vector<pair<int, int> > victim;

int x_dir[4] = { 0, -1, 0, 1 };
int y_dir[4] = { -1, 0, 1, 0 };

void bfs(int start_x, int start_y) {
    ans = 0;

    int cur_x = start_x;
    int cur_y = start_y;

    while (1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }

        printf("\n-------------------\n");
        printf("current ans: %d", ans);
        printf("\n-------------------\n\n");

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = -1;

        dist[cur_x][cur_y] = 0;
        map[cur_x][cur_y] = 0;

        q = queue<pair<int,int> > ();
        victim.clear();

        if (eat_cnt == shark_size) {
            eat_cnt -= shark_size;
            shark_size++;
        }

        q.push(make_pair(cur_x, cur_y));

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int x_new = x + x_dir[i];
                int y_new = y + y_dir[i];

                if (x_new < 1 || x_new > n || y_new < 1 || y_new > n) continue;
                if (dist[x_new][y_new] != -1) continue;

                if (map[x_new][y_new] > shark_size) continue;

                else if ((map[x_new][y_new] == shark_size) || (map[x_new][y_new] == 0)) {
                    dist[x_new][y_new] = dist[x][y] + 1;
                    q.push(make_pair(x_new, y_new));
                }

                else if ((map[x_new][y_new] < shark_size) || (map[x_new][y_new] > 0)) {
                    dist[x_new][y_new] = dist[x][y] + 1;
                    victim.push_back(make_pair(x_new, y_new));
                    q.push(make_pair(x_new, y_new));
                }
            }
        }

        if (victim.size() == 0) {
            printf("%d\n", ans);
            return;
        }

        else if (victim.size() == 1) {
            int x = victim[0].first;
            int y = victim[0].second;
            map[x][y] = 0;
            eat_cnt++;
            ans += dist[x][y];
            
            cur_x = x;
            cur_y = y;
        }

        else {
            int min_dist = 1e5;

            for (pair<int, int> _victim : victim)
                min_dist = min(min_dist, dist[_victim.first][_victim.second]);
            
            vector<pair<int, int> > min_victim;

            for (pair<int, int> _victim : victim) {
                if (min_dist == dist[_victim.first][_victim.second])
                    min_victim.push_back(make_pair(_victim.first, _victim.second));
            }

            if (min_victim.size() == 1) {
                int x = min_victim[0].first;
                int y = min_victim[0].second;

                map[x][y] = 0;
                eat_cnt++;
                ans += dist[x][y];

                cur_x = x;
                cur_y = y;
            }

            else {
                sort(min_victim.begin(), min_victim.end());

                int x = min_victim[0].first;
                int y = min_victim[0].second;

                map[x][y] = 0;
                ans += dist[x][y];
                eat_cnt++;

                cur_x = x;
                cur_y = y;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 9) {
                start.first = i;
                start.second = j;
            }
        }
    }
    printf("\n");

    shark_size = 2, eat_cnt = 0;

    bfs(start.first, start.second);

    return 0;
}