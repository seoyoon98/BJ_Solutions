#include <iostream>

using namespace std;

int n, k;

int calculator(int a, int b);

int main() {
    cin >> n >> k;

    cout << calculator(n, k) << endl;

    return 0;
}

int calculator(int a, int b) {
    if ((a > 1) && (b - 1 >= 0)) {
        if (a == b)
            return 1;

        else if (b == 1)
            return a;

        else
            return calculator(a - 1, b - 1) + calculator(a - 1, b);
    }

    else if (a == 1 || b == 0)
        return 1;
}