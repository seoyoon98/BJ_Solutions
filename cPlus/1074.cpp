#include <iostream>

using namespace std;

#define MAX_N 16

int N, r, c;
int board[MAX_N][MAX_N];

int Z_count(int n, int row, int col) {
    if (n == 0) return 0;

    int half = 1 << (n-1);

    if (row <= half && col <= half ) return Z_count(n - 1, row, col);
    else if (row <= half && col > half ) return half * half + Z_count(n - 1, row, col - half);
    else if (row > half && col <= half ) return 2 * half * half + Z_count(n - 1, row - half, col);
    else return 3 * half * half + Z_count(n - 1, row - half, col - half);
}

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> r >> c;

    cout << Z_count(N, r + 1, c + 1) << '\n';

    return 0;
}