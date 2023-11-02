#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int num, ans;

vector<int> v;

void input() {
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
}

int LIS() {
    vector<int> lis;

    vector<int>::iterator iter;

    for (int i = 0; i < num; i++) {
        iter = lower_bound(lis.begin(), lis.end(), v[i]);

        if (iter == lis.end())
            lis.push_back(v[i]);
        else
            *iter = v[i];

        // for (auto x: lis)
        //     printf("%d ", x);
        // printf("\n=======================\n");
    }

    return lis.size();
}

int main() {
    setbuf(stdout, NULL);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();

    ans = num - LIS();
    printf("%d\n", ans);

    return 0;
}