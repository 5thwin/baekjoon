#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;

ll dp[101];
ll d_max(ll a, ll b)
{
	return a > b ? a : b;
}

int main()
{
	int N;
	scanf("%d", &N);
	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; i - 2 - j >= 0; j++)
		{
			dp[i] = d_max(dp[i], dp[i - 2 - j] * (j + 1));
		}
	}
	printf("%lld", dp[N]);
}