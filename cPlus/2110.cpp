#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200001
#define ll long long

using namespace std;

ll house_num, router_num, ans, min_d, max_d, router_cnt;
vector<ll> house_x;

void binary_search(ll left, ll right) {
    //printf("left: %lld, right: %lld, ans: %lld\n", left, right, ans);
    if (left > right) return;

    router_cnt = 1;
    ll mid = (left + right) / 2;
    ll start = house_x.front();

    for (ll i = 1; i < house_num; ++i) {
        ll end = house_x[i];

        if (end - start >= mid) {
            router_cnt++;
            start = end;
        }
    }

    if (router_cnt >= router_num) {
        ans = max(ans, mid);
        binary_search(mid + 1, right);
    }
    else
        binary_search(left, mid - 1);
}

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%lld %lld", &house_num, &router_num);

    for (int i = 0; i < house_num; ++i) {
        ll temp;
        scanf("%lld", &temp);
        house_x.push_back(temp);
    }

    sort(house_x.begin(), house_x.end());

    min_d = 1;
    max_d = house_x.back() - house_x.front();

    //printf("min: %lld, max: %lld\n", min_d, max_d);
    binary_search(min_d, max_d);

    printf("%lld\n", ans);

    return 0;
}