#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef long long ll;

const ll MAX = 100005;
ll T, N, M, arr[MAX], sum[MAX];

// 1
// 6 3
// 3 1 4 6 6 5
// 4 2 5
// 얻어갈 수 있는 포인트
// 1. 구간합 디피(prefix sum)
// 2. - 사용해서 절댓값 바꾸는 방법
// 3. 맵 사용법
// 4. 어퍼바운드
// 참고: 어퍼 - 해당 값 초과하면서 가장 작은 || 로어 - 해당 값 이상 그리고 가장 작은

std::vector<ll> ans;

int main() {
    setbuf(stdout, NULL);

    scanf("%lld", &T);
    for(ll z = 1; z <= T; ++z){
        ll max_res = -1;

        std::map<ll, ll> slice, val;
        scanf("%lld %lld", &N, &M);

        for(ll i = 0; i < N; ++i){
            scanf("%lld", &arr[i]);
            sum[i + 1] = sum[i] + arr[i];
        }
        // 1 2 3 4 5
        // -5 -4 -3 -2 -1

        slice[-1] = sum[N];
        val[sum[N]] = 1;

        for(ll i = 0; i < M; ++i){
            ll query;
            std::map<ll, ll>::iterator it;

            scanf("%lld", &query);
            
            it = slice.upper_bound(-query);

            // 여기서 if(it == slice.end()) 해줘야하지만
            // 문제 조건 상 예외 사항 없으므로 그대로 감
            if(val[it->second] == 1)
                val.erase(it->second);

            else
                val[it->second] -= 1;

            slice[-query] = slice[it->first] - (sum[query - 1] - sum[-it->first - 1]);
            slice[it->first] -= slice[-query];

            if(val.find(slice[-query]) != val.end())
                val[slice[-query]] += 1;
            else
                val[slice[-query]] = 1;

            if(val.find(slice[it->first]) != val.end())
                val[slice[it->first]] += 1;
            else 
                val[slice[it->first]] = 1;
             
            ans.push_back((--val.end())->first);
        }

    }

    ll cnt  = 1;
    for (ll x : ans)
        printf("#%lld %lld\n", cnt++, x);
    
    return 0;
}