#include <iostream>
#include <limits.h>

#define ll long long
#define MAX 1000001

using namespace std;

ll n, m, k, case_num;
ll arr[MAX];
ll seg[MAX * 4];

void input() {
    scanf("%lld %lld %lld", &n, &m, &k);
    m += k;

    for (ll i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);    
}

ll init(ll arr[], ll seg[], ll node, ll start, ll end) {
    if (start == end)
        return seg[node] = arr[start];

    ll mid = (start + end) / 2;
    return seg[node] = init(arr, seg, node * 2, start, mid) + init(arr, seg, node * 2 + 1, mid + 1, end);
}

ll sum(ll seg[], ll node, ll start, ll end, ll left, ll right) {
    if (left > end || right < start) return 0;
    if (left <= start &&  end <= right) return seg[node];

    ll mid = (start + end) / 2;
    return sum(seg, node * 2, start, mid, left, right) + sum(seg, node * 2 + 1, mid + 1, end, left, right);
}

void update(ll seg[], ll node, ll start, ll end, ll index, ll diff) {
    if (index > end || index < start) return;
    
    seg[node] += diff;
    if (start != end) {
        ll mid = (start + end) / 2;
        update(seg, node * 2, start, mid, index, diff);
        update(seg, node * 2 + 1, mid + 1, end, index, diff);
    }

    return;
}

int main() {
    setbuf(stdout, NULL);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    init(arr, seg, 1, 1, n);

    for (ll i = 1; i <= m; i++) {
        scanf("%lld", &case_num);

        switch (case_num) 
        {
            case 1:
            {
                ll index, value;
                scanf("%lld %lld", &index, &value);
                ll diff = value - arr[index];
                arr[index] = value; // Update the original array value here
                update(seg, 1, 1, n, index, diff);
                break;
            }
    
            case 2:
            {
                ll start, end;
                scanf("%lld %lld", &start, &end);
                printf("%lld\n", sum(seg, 1, 1, n, start, end));
                break;
            }
        }
    }

    return 0;
}