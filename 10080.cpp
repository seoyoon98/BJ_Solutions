#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200001

using namespace std;

int ball_num, sum;
int same_color[MAX], same_size[MAX], ans[MAX];

struct ball {
    int weight, color, index;
};

vector<ball> v;

bool cmp(ball &a, ball &b) {
    if (a.weight == b.weight)
        return a.color < b.color;
    return a.weight < b.weight;
}

void input() {
    scanf("%d", &ball_num);

    for (int i = 0; i < ball_num; i++) {
        int weight, color;
        scanf("%d %d", &color, &weight);
        
        ball b;
        b.weight = weight;
        b.color = color;
        b.index = i;
        v.push_back(b);
    }

    sort(v.begin(), v.end(), cmp);
}

int main() {
    setbuf(stdout, NULL);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();

    for (int i = 0; i < v.size(); i++) {
        int weight, color, index;
        weight = v[i].weight;
        color = v[i].color;
        index = v[i].index;

        same_color[color] += weight;
        same_size[weight] += weight;
        sum += weight;

        ans[index] = sum - same_color[color] - same_size[weight] + weight;

        if ((i != 0) && (v[i - 1].weight == weight) && (v[i - 1].color == color))
            ans[index] = ans[v[i - 1].index];
    }

    for (int i = 0; i < ball_num; i++)
        printf("%d\n", ans[i]);

    return 0;
}