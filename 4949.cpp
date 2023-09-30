#include <iostream>
#include <stack>
#include <string>

using namespace std;

string inputStr;
stack<char> s;

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1) {
        getline(cin, inputStr);

        if (inputStr.compare(".") == 0) break;

        for (int i = 0; i < inputStr.length(); ++i) {
            if (inputStr[i] == '(' || inputStr[i] == '[')
                s.push(inputStr[i]);

            else if (inputStr[i] == ')') {
                if (!s.empty()) {
                    if (s.top() == '(')
                        s.pop();
                    else
                    s.push(inputStr[i]);
                }
                
                else
                    s.push(inputStr[i]);
            }

            else if (inputStr[i] == ']') {
                if (!s.empty()) {
                    if (s.top() == '[')
                        s.pop();
                    else
                    s.push(inputStr[i]);
                }
                
                else
                    s.push(inputStr[i]);
            }
        }

        if (s.empty())
            cout << "yes\n";
        else   
            cout << "no\n";

        while(!s.empty())
            s.pop();
    }

    return 0;
}