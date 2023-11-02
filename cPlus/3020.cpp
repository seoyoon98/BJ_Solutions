#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, H; // 2 <= N(동굴 길이) <= 200,000, 2 <= H(동굴 높이) <= 500,000

vector<int> odd;
vector<int> even;

int min_result, min_cnt, result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H;

    odd.resize(H + 1), even.resize(H + 1);

    for (int i = 0; i < N / 2; i++) {
        int odd_num, even_num;
        cin >> odd_num >> even_num;
        odd[odd_num]++;
        even[H + 1 - even_num]++;
    }

    for (int i = 0; i <= H; i++)
        even[i + 1] += even[i];

    for (int i = H; i >= 1; i--)
        odd[i - 1] += odd[i];

    min_cnt = 1; min_result = 987654321;

    for (int i = 1; i <= H; i++) {
        result = odd[i] + even[i];
        // cout << "result" << i << ": " << result[i] << " = " << "odd" << i << ": " << odd[i] << " + " << "even" << i << ": " << even[i] << "\n";       

        if (result < min_result) {
            min_result = result;
            min_cnt = 1; 
        }
        else if (result == min_result)
            min_cnt++;
    }

    cout << min_result << " " << min_cnt << "\n";

    return 0;
}