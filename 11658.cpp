#include <iostream>

#define MAX 1025

using namespace std;

// 1<=N<=1024, 1<=M<=100000
int N, M, table[MAX][MAX], case_num, x, y, val, start_x, start_y, end_x, end_y;
int tree[MAX][MAX];

void update(int r, int c, int change_val) {
    for (int row = r; row <= N; row += (row & -row))
        for (int col = c; col <= N; col += (col & -col))
            tree[row][col] += change_val;
}

int sum(int r, int c){
    int result = 0;

    for (int row = r; row >= 1; row -= (row & -row))
        for (int col = c; col >= 1; col -= (col & -col))
            result += tree[row][col];

    return result;
}

void value_input() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &table[i][j]);
            update(i, j, table[i][j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    value_input();

    for (int i = 1; i <= M; i++) {
        scanf("%d", &case_num);

        switch(case_num) {
            case 0:
            {
                scanf("%d %d %d", &x, &y, &val);
                update(x, y, val - table[x][y]);
                table[x][y] = val;
                break;
            }

            case 1:
            {
                scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
                int answer = sum(end_x, end_y) - sum(end_x, start_y - 1) - sum(start_x - 1, end_y) + sum(start_x - 1, start_y - 1);
                printf("%d\n", answer);
                break;
            }
        }
    }

    return 0;
}

int sum(vector<int> &tree, int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += tree[i];
        i -= (i & -i); // 최하위 비트 지우기 
    }

    for (int index = i; index > 0; index -= (index & -index)) {
        ans += tree[i];
    }
 
    return ans;
}
 
void update(vector<int> &tree, int i, int diff)
{
    while (i < tree.size())
    {
        tree[i] += diff;
        i += (i & -i);
    }
}