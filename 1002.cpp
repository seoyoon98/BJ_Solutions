#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int aX, aY, bX, bY, aR, bR;

int main() {
    int testCase;
    cin >> testCase;

    int distance; // distance between two centers

    while(testCase--) {
        cin >> aX >> aY >> aR >> bX >> bY >> bR;
        distance = (aX - bX) * (aX - bX) + (aY - bY) * (aY - bY);
        int plus = (aR + bR) * (aR + bR);
        int sub = (aR - bR) * (aR - bR);

        //cout << distance << ' ' << plus << ' ' << sub << endl;

        if (distance == 0) {
            if (aR == bR)
                cout << -1 << endl;
            else
                cout << 0 << endl;
        }

        else {
            if (distance > plus)
                cout << 0 << endl;
            else if (distance == plus) 
                cout << 1 << endl;
            else {
                if (distance > sub)
                    cout << 2 << endl;
                else if (distance == sub)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
        }
    }
    
    return 0;
}