#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair
#define INF 987654321
typedef long long ll;

using namespace std;

int N;
int dp[1000001], oper[1000001];
//연산 1 : 1빼기 2 : 2로 나누기 3 : 3 나누기
int minidx(int candid[4])
{
	for (int i = 1; i < 4; i++)
	{
		if (candid[i] > candid[1])
			continue;
		if (candid[i] > candid[2])
			continue;
		if (candid[i] > candid[3])
			continue;
		return (i);
	}
	return (0);
}

int solve(int x)
{
	int &ret = dp[x];
	if (ret != -1)
		return ret;
	if (x == 1)
	{
		return ret = 0;
	}
	if (x == 2)
	{
		oper[x] = 1;
		return ret = 1;
	}
	if (x == 3)
	{
		oper[x] = 3;
		return ret = 1;
	}
	int candid[4] = {INF, INF, INF, INF};
	if (x % 3 == 0)
		candid[3] = solve(x / 3);
	if (x % 2 == 0)
		candid[2] = solve(x / 2);
	candid[1] = solve(x - 1);
	int mini = minidx(candid);
	oper[x] = mini;
	return ret = candid[mini] + 1;
}
int main()
{
	FAST;
	cin >> N;
	memset(dp, -1, sizeof(dp));
	memset(dp, -1, sizeof(dp));
	cout << solve(N) << "\n";
	int x = N;
	while (oper[x] >= 0)
	{
		cout << x << " ";
		if (oper[x] == 3)
			x = x / 3;
		else if (oper[x] == 2)
			x = x / 2;
		else if (oper[x] == 1)
			x--;
		else
			break;
	}
}
