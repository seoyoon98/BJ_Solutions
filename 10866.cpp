#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> dq;
string op;

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int query;
    cin >> query;

    while(query--) {
        cin >> op;

        if (op.compare("push_front") == 0) {
            int temp;
            cin >> temp;
            dq.push_front(temp);
        }

        else if (op.compare("push_back") == 0) {
            int temp;
            cin >> temp;
            dq.push_back(temp);
        }

        else if (op.compare("front") == 0) {
            if (!dq.empty())
                cout << dq.front() << "\n";
            else
                cout << -1 << "\n";
        }

        else if (op.compare("back") == 0) {
            if (!dq.empty())
                cout << dq.back() << "\n";
            else
                cout << -1 << "\n";
        }

        else if (op.compare("pop_front") == 0) {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else
                cout << -1 << "\n";
        }

        else if (op.compare("pop_back") == 0) {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else
                cout << -1 << "\n";
        }

        else if (op.compare("size") == 0)
            cout << dq.size() << "\n";

        else if (op.compare("empty") == 0)
            cout << dq.empty() << "\n";
    }

    return 0;
}