#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<int> q;
string op;

int main() {
    int query;
    cin >> query;

    for (int z = 0; z < query; ++z) {
        cin >> op;

        if (op.compare("push") == 0) {
            int temp;
            cin >> temp;
            q.push(temp);
        }

        else if (op.compare("front") == 0) {
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << -1 << "\n";
        }

        else if (op.compare("back") == 0) {
            if (!q.empty())
                cout << q.back() << "\n";
            else
                cout << -1 << "\n";
        }

        else if (op.compare("empty") == 0) {
            cout << q.empty() << "\n";
        }

        else if (op.compare("size") == 0) {
            cout << q.size() << "\n";
        }

        else if (op.compare("pop") == 0) {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
            else
                cout << -1 << "\n";
        }
    }

    return 0;
}