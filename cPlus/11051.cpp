#include<iostream>

using namespace std;

int n, k;
long long DP[1001][1001];

int main()
{
	cin >> n >> k;

	DP[0][0] = 1, DP[1][1] = 1, DP[1][0] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0)
				DP[i][0] = 1;
			else if	(j == i)
				DP[i][j] = 1;
			else
				DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]) % 10007;
		}
	}	

	cout << DP[n][k] << endl;
}

// 출처: https://cocoon1787.tistory.com/220