#include <iostream>

#define INF 1e9
#define MAX 100

using namespace std;

// 2<=n<=100, 1<=m<=100000
int n, m;
int dp[MAX][MAX];

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int start = 0; start < n; start++) {
            for (int end = 0; end < n; end++) {
                if (dp[start][end] > dp[start][k] + dp[k][end])
                    dp[start][end] = dp[start][k] + dp[k][end];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (dp[from - 1][to - 1] != INF) {
            if (dp[from - 1][to - 1] > cost)
                dp[from - 1][to - 1] = cost;
        } 
        else {
            dp[from - 1][to - 1] = cost;
        }
    }

    // cout << "\nAfter Input\n\n";

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    floydWarshall();

    return 0;
}