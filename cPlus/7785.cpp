#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int queryNum;
string name, isEnter;
set<string, greater<string> > s;

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> queryNum;

    while(queryNum--) {
        cin >> name >> isEnter;

        if (isEnter.compare("enter") == 0)
            s.insert(name);
        else if (isEnter.compare("leave") == 0)
            s.erase(name);
    }

    for (auto x : s)
        cout << x << "\n";

    return 0;
}