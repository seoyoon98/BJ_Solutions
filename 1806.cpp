// #include <iostream>

// using namespace std;

// int main() {
//     setbuf(stdout, NULL);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s, mn = 0x7FFFFFFF;

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    vector<int> v(n);

    for (int i = 0 ; i < n; ++i)
        cin >> v[i];

    int tot = v[0], en = 0;
    for (int st = 0; st < n; ++st) {
        while(en < n && tot < s) {
            en++;
            if (en != n) tot += v[en];
        }
        
        if (en == n) break;

        int len = en - st + 1;
        mn = min(mn, len);
        tot -= v[st];
    }

    if (mn == 0x7FFFFFFF) mn = 0;
    cout << mn <<'\n';
    return 0;
}