#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> s;

int main()
{
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int query_num;
    string op;

    cin >> query_num;

    for (int i = 0; i < query_num; ++i)
    {
        cin >> op;

        if (op.compare("push") == 0) {
            int temp;
            cin >> temp;
            s.push(temp);
        }

        else if (op.compare("top") == 0) {
            if (!s.empty())
                cout << s.top() << "\n";
            else
                cout << -1 << "\n";
        }

        else if (op.compare("size") == 0)
            cout << s.size() << "\n";

        else if (op.compare("empty") == 0)
            cout << (s.empty() ? 1 : 0) << "\n";
        
        else if (op.compare("pop") == 0) { // 명시적으로 "pop" 명령어 확인
            if (!s.empty()) {
                cout << s.top() << "\n";
                s.pop();
            }

            else
                cout << -1 << "\n";
        }
    }

    return 0;
}