#include <iostream>
#include <cstdio>

#define MAX 501

using namespace std;

// 1<=n<=500
int n;
int map[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);

    return 0;
}