// hash set 사용

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<string> arr(n);
        for (int j = 0; j < n; ++j)
            cin >> arr[j];
        
        sort(arr.begin(), arr.end()); // 정렬
        unordered_set<string> hash_set;
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            string str = ""; // arr[j]의 접두어
            for (int k = 0; k < arr[j].length() - 1; ++k) { //문제에서 같은 단어가 주어지는 경우는 없다고 했기 때문에 lengh() - 1
                str += arr[j][k]; // 접두어 만들기
                if (hash_set.find(str) != hash_set.end()) {
                    flag = true;
                    cout << "NO" << '\n';
                    break;
                }
            }
            if (flag) break;
            hash_set.insert(arr[j]); // 현재 단어 추가
        }
        if (!flag) cout << "YES" << '\n';
    }
}