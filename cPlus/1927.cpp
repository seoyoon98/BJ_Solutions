#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int heap[100005];
int sz = 0;

void push(int x) {
    heap[++sz] = x;
    int idx = sz;

    while(idx != 1) {
        int par = idx / 2;
        if (heap[par] <= heap[idx]) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int top() {
    return heap[1];
}

void pop() {
    if (sz != 0) {
        heap[1] = heap[sz--];
        int idx = 1;

        //cout << "sz: " << sz << '\n';

        while (2 * idx <= sz){
            int lc = 2 * idx, rc = 2 * idx + 1;
            int min_child = lc;

            if (rc <= sz && heap[rc] < heap[lc])
                min_child = rc;

            if (heap[idx] <= heap[min_child])
                break;

            swap(heap[idx], heap[min_child]);
            idx = min_child;
        }

        if (sz == 0)
            heap[1] = 0;
    }
}

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int queryNum;

    cin >> queryNum;

    while(queryNum--) {
        int x;
        cin >> x;

        if (x == 0) {
            cout << top() << '\n';
            pop();
        }

        else
            push(x);
    }

    return 0;
}