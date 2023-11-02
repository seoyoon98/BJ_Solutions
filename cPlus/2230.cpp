#include <iostream>
#include <vector>

using namespace std;

int n, m, mn = 0x7FFFFFFF;

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<int> v(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    int en = 0;
    for (int st = 0; st < n; ++st) {
        while (en < n && v[en] - v[st] < m)
            en++;

        if (en == n) break;

        mn = min(mn, v[en] - v[st]);
    }

    if (mn == 0x7FFFFFFF) mn = 0;

    cout << mn << '\n';

    return 0;
}