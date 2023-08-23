#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2001
#define ll long long

using namespace std;

ll n, good_num;
vector<ll> nums;

int main() {
    setbuf(stdout, NULL);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%lld", &n);

    for (ll i = 0; i < n; i++) {
        ll temp;
        scanf("%lld", &temp);
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());   

    ll start, end, sum;
    good_num = 0;

    for (ll i = 0; i < n; i++) {
        start = 0, end = n - 1;

        while (start < end) {
            sum = nums[start] + nums[end];
            //printf("\n[ i: %lld, start: %lld, end: %lld ]\n", i, start, end);

            if (sum == nums[i]) {
                if (start != i && end != i) {
                    //printf("\ni: %lld, sum: %lld, start: %lld, end: %lld\n", i, sum, start, end);
                    good_num++;
                    break;
                }
                else if (start == i) start++;
                else if (end == i) end--;
            }
            else if (sum < nums[i])
                start++;
            else
                end--;

        }
    }

    printf("%lld\n", good_num);

    return 0;
}