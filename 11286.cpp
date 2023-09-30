#include <iostream>
#include <queue>

using namespace std;

int queryNum, inputNum;

priority_queue<int, vector<int>, greater<int> > plusPQ;
priority_queue<int> minusPQ;

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> queryNum;

    while(queryNum--) {
        cin >> inputNum;

        if (inputNum > 0)
            plusPQ.push(inputNum);

        else if (inputNum < 0)
            minusPQ.push(inputNum);

        else {
            if (plusPQ.size() == 0 && minusPQ.size() == 0)
                cout << 0 << '\n';

            else if (plusPQ.size() != 0 && minusPQ.size() == 0) {
                cout << plusPQ.top() << '\n';
                plusPQ.pop();
            }

            else if (plusPQ.size() == 0 && minusPQ.size() != 0) {
                cout <<  minusPQ.top() << '\n';
                minusPQ.pop();
            }
            
            else {
                int minPlus = plusPQ.top();
                int minMinus = -1 * minusPQ.top();

                if (minMinus <= minPlus && minMinus != 0) {
                    cout <<  minusPQ.top() << '\n';
                    minusPQ.pop();
                }

                else if (minMinus > minPlus && minPlus != 0) {
                    cout << plusPQ.top() << '\n';
                    plusPQ.pop();
                }
            }
        }

        //cout << "minus: " << minusPQ.size() << " & " << "plus: " << plusPQ.size() << '\n';
    }

    return 0;
}