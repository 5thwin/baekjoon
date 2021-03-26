#include<cstdio>
#include<cstring>
#define MOD 1000000009
typedef long long ll;
using namespace std;

ll dp[100001][3];
ll solve(int n, int last)
{
	if (n - last < 0) return 0;
	ll& ret = dp[n][last-1];
	if (ret != -1)
		return ret;
	if (n == last)
		return ret = 1;
	if (last == 1)
		return ret = (solve(n - 1, 2) + solve(n - 1, 3))%MOD;
	if (last == 2)
		return ret = (solve(n - 2, 1) + solve(n - 2, 3))%MOD;
	else //last == 3
		return ret = (solve(n - 3, 1) + solve(n - 3, 2))%MOD;
}
int main()
{
	int T, input;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	while (T--)
	{
		scanf("%d", &input);
		printf("%lld\n", (solve(input, 1) + solve(input, 2) + solve(input, 3)) % MOD);
	}
}
/*
3
4
7
10
*/