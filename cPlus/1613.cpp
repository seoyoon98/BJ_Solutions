#include <iostream>

#define INF 1e9
#define MAX 401

using namespace std;

// 1<=n<=400 , 1<=k<= 50000, 1<=s<=50000
int n, k, s;

int graph[MAX][MAX];

void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int start = 1; start <= n; start++) {
            for (int end = 1; end <= n; end++) {
                if (graph[start][end] > graph[start][k] + graph[k][end])
                    graph[start][end] = graph[start][k] + graph[k][end];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    for (int i = 1; i <= k; i++) {
        int start, end;
        scanf("%d %d", &end, &start);
        graph[start][end] = 1;
    }

    floyd_warshall();

    // printf("\n");
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         printf("%d ", graph[i][j]);
    //     }
    //     printf("\n");
    // }

    scanf("%d", &s);

    for (int i = 0; i < s; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if (graph[a][b] == INF && graph[b][a] == INF)
            printf("%d\n", 0);
        else if (graph[a][b] != INF && graph[b][a] == INF)
            printf("%d\n", 1);
        else if (graph[a][b] == INF && graph[b][a] != INF)
            printf("%d\n", -1);
    }

    return 0;
}