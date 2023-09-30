#include <iostream>
#include <set>

using namespace std;

int testNum, queryNum, input;
char op;

multiset<int> ms;

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> testNum;

    while(testNum--) {
        cin >> queryNum;

        while(queryNum--) {
            cin >> op >> input;

            if (op == 'I')
               ms.insert(input); 

            else if (op == 'D') {
                if (!ms.empty()) {
                    if (input == 1)
                        ms.erase(prev(ms.end()));

                    else if (input == -1)
                        ms.erase(ms.begin());
                }
            }

            // for (auto x: ms) {
            //     cout << x << " ";
            // }
            // cout << "\n";
        }

        if (ms.empty()) cout << "EMPTY\n";
        else
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';

        ms.clear();
    }

    return 0;
}