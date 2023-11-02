#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testNum;
    cin >> testNum;

    int x1, y1, x2, y2;
    int count;
    int distance1, distance2;
    int planetaryNum;

    for (int i = 0; i < testNum; ++i) {
        int count = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> planetaryNum;

        int cx, cy, cr;
        for (int j = 0; j < planetaryNum; ++j) {
                cin >> cx >> cy >> cr;
                distance1 = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 -cy);
                distance2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 -cy);

                if (distance1 < cr * cr) {
                    if (distance2 > cr * cr)
                        count++;
                }

                else {
                    if (distance2 < cr * cr)
                        count++;
                }
        }
        
        cout << count << endl;
    }

    return 0;
}