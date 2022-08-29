#include<iostream>
using namespace std;

int N, K;
long long DP[1001][1001];

//점화식 DP[N][K] =DP[N-1][K-1] + DP[N-1][K] 

int main()
{
	cin >> N >> K;

	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[1][1] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) DP[i][0] = 1;
			else if (j == i) DP[i][j] = 1;
			else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % 10007;
			// 매번 10007로 나눠주지 않으면 자료형의 크기를 초과하게 됨.
		}
			

	cout << DP[N][K];
}

// 출처: https://cocoon1787.tistory.com/220