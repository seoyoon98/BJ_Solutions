#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, mx = 0;
vector<int> v;
set<int> s;


int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n ; ++j)
            s.insert(v[i]+ v[j]);

    int en = 0;

    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (s.find(v[i] - v[j]) != s.end()) {
                cout << v[i] << '\n';
                return 0;
            }
        }
    }

    return 0;
}