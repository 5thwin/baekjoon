#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MOD 1000000
typedef long long ll;
using namespace std;

int N;
int dp[100][100][2];
int solve(int up, int down, bool flag) //flag == 0 -> 이전 것보다 작은 것중에 하나 1-> 이전것보다 큰 것중에 하나
{
	int& ret = dp[up][down][flag];
	if (up == 0 && down == 0)
		return (1);
	if (ret != -1)
		return ret;
	ret = 0;
	if (flag == 0) //down 중에서 하나
	{
		if (down == 0) return ret;
		for (int i = 0; i < down; i++) 
		{
			ret += solve(up + down -(i + 1), i, !flag);
			ret %= MOD;
		}
	}
	else if (flag == 1) // up 중에서 하나
	{
		if (up == 0) return ret;
		for (int i = 0; i < up; i++)
		{
			ret += solve(up - i - 1, down + i, !flag);
			ret %= MOD;
		}
	}
	return ret;
}
int main()
{
	FAST;
	cin >> N;
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	if (N == 1)
	{
		cout << "1";
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		ans += solve(N - i - 1, i, 0);
		ans %= MOD;
		ans += solve(N - i - 1, i, 1);
		ans %= MOD;
	}
	cout << ans;
}