/*알약*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int N;
ll dp[31][31]; //dp[a][b] = 병에 a개 약과 b개 반쪽자리 약이 있을때 나오는 문자열의 경우의 수
ll solve(int a, int b)
{
	ll &ret = dp[a][b];
	if (ret != -1)
		return ret;
	if (a == 0 && b == 0)
		return ret = 0;
	if (a == 0 && b > 0)
		return ret = 1;
	if (a > 0 && b == 0)
		return ret = solve(a - 1, b + 1);
	return ret = solve(a - 1, b + 1) + solve(a, b - 1);
}
int main() {
	FAST;
	memset(dp, -1, sizeof(dp));
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;
		cout << solve(N, 0) << "\n";
	}
}

