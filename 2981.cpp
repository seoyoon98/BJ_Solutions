#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    //cout << n << endl;

    vector<int> vN; // vector of N numbers
    vector<int> vM; // vector of M numbers
    int temp;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        vN.push_back(temp);
    }

    sort(vN.begin(), vN.end());

    int remain;
    //cout << remain << endl;

    for (int i = 2; i <= vN[0]; ++i) {
        for (int k = 0; k < n; ++k) {
            remain = vN[0] % i;
            
            if (vN[k] % i != remain)
                break;
            
            if (k == n - 1)
                vM.push_back(i);
        }
    }

    for (int i = vN[0] + 1; i < vN[1]; ++i) {
        for (int k = 1; k < n; ++k) {
            remain = vN[0];
            
            if (vN[k] % i != remain)
                break;

            if (k == n - 1)
                vM.push_back(i);
        }
    }

    for(int i = 0; i < vM.size(); ++i) {
        cout << vM[i] << ' ';
    }
    cout << "\n";

    return 0;
}