#include <iostream>
#include <vector>
#include <algorithm>
#include<cstdio>

#define MAX 100001
#define INT_MAX 1e9

using namespace std;

// 1<=N,M<=100000
int N, M;

vector<int> input;

int max_seg[4 * MAX];
int min_seg[4 * MAX];

// node: 부모 노드 / start, end: 구간 시작, 끝
int min_init(int node, int start, int end) {
    if (start == end)
        return min_seg[node] = input[start]; // start 와 end 의 위치가 일치하면 input[start] 값을 넣어준다.
    int mid = (start + end) / 2;
    return min_seg[node] = min(min_init(2 * node, start, mid), min_init(2 * node + 1, mid + 1, end)); // 다른 노드들의 정보를 
}

int max_init(int node, int start, int end) {
    if (start == end)
        return max_seg[node] = input[start]; // start 와 end 의 위치가 일치하면 input[start] 값을 넣어준다.
    int mid = (start + end) / 2;
    return max_seg[node] = max(max_init(2 * node, start, mid), max_init(2 * node + 1, mid + 1, end)); // 다른 노드들의 정보를 
}

int min_query(int node, int start, int end, int left, int right) {
    if (end < left || start > right) return INT_MAX;
    if (left <= start && end <= right) return min_seg[node];

    int mid = (start + end) / 2;
    return min(min_query(2 * node, start, mid, left, right), min_query(2 * node + 1, mid + 1, end, left, right));
}

int max_query(int node, int start, int end, int left, int right) {
    if (end < left || start > right) return -INT_MAX;
    if (left <= start && end <= right) return max_seg[node];

    int mid = (start + end) / 2;
    return max(max_query(2 * node, start, mid, left, right), max_query(2 * node + 1, mid + 1, end, left, right));
}

int main() {
    ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    // cin >> N >> M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        int temp;
        // cin >> temp;
        scanf("%d", &temp);
        input.push_back(temp);
    }

    min_init(1, 0, N - 1);
    max_init(1, 0, N - 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        // cout << min_query(1, 0, N - 1, a - 1, b - 1) << " " << max_query(1, 0, N - 1, a - 1, b - 1) << "\n";
        printf("%d %d\n", min_query(1, 0, N - 1, a - 1, b - 1), max_query(1, 0, N - 1, a - 1, b - 1));
    }

    return 0;
}