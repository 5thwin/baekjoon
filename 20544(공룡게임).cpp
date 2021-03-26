#include<cstdio>
#include<cstring>
#define MOD 1000000007
typedef long long ll;

using namespace std;

ll dp[1001][3][3];
ll edp[1001][2][2];
ll N;
ll solve(int n, int h, int next)
{
	if (n < 0)
		return 0;
	ll& ret = dp[n][h][next];
	if (ret != -1)
		return ret;
	if (n == 0)
	{
		if (h == 0)
			return ret = 1;
		else
			return ret = 0;
	}


	if (h == 0)
	{
		return ret = (solve(n - 1, 2, h) + solve(n - 1, 1, h) + solve(n - 1, 0, h)) % MOD;
	}
	if (h == 1)
	{
		if (next == 0)
			return ret = (solve(n - 1, 2, h) + solve(n - 1, 1, h) + solve(n - 1, 0, h)) % MOD;
		if (next == 1 || next == 2)
			return ret = solve(n - 1, 0, h) % MOD;
	}
	if (h == 2)
	{
		if (next == 2)
			return ret = 0;
		if (next == 1)
			return ret = solve(n - 1, 0, h) % MOD;
		if (next == 0)
			return ret = (solve(n - 1, 1, h) + solve(n - 1, 0, h)) % MOD;
	}
}
ll exception(int n, int h, int next)
{
	if (n < 0)
		return 0;
	ll& ret = edp[n][h][next];
	if (ret != -1)
		return ret;
	if (n == 0)
	{
		if (h == 0)
			return ret = 1;
		else
			return ret = 0;
	}

	if (h == 0)
	{
		return ret = (exception(n - 1, 1, h) + exception(n - 1, 0, h)) % MOD;
	}
	if (h == 1)
	{
		if (next == 0)
			return ret = (exception(n - 1, 1, h) + exception(n - 1, 0, h)) % MOD;
		if (next == 1)
			return ret = exception(n - 1, 0, h) % MOD;
	}

}
int main()
{
	ll all, excep;
	memset(dp, -1, sizeof(dp));
	memset(edp, -1, sizeof(edp));

	scanf("%d", &N);
	if (N == 1)
		printf("0\n");
	else
	{
		all = (solve(N - 1, 0, 0) + solve(N - 1, 1, 0) + solve(N - 1, 2, 0));
		excep = (exception(N - 1, 0, 0) + exception(N - 1, 1, 0));
		printf("%lld\n", (all - excep) % MOD);
	}
}