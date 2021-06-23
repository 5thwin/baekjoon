#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define NINF -987654321
typedef long long ll;
using namespace std;
int N;
vector<int> input;
vector<vector<int> > dp;
//dp[n][d] : 첫번째부터 n번째 범위 내에서 n을 포함했을때의 연속합의 최댓값, d - 0~n번째 중에서 제외 유무
int solve(int n, int d)
{
	int &ret = dp[n][d];
	if (ret != NINF)
		return ret;
	if (n == 0)
	{
		if (d == 0)
			return ret = input[n];
		else
			return ret = NINF;
	}
	if (d == 1)
		ret = max(solve(n - 1, 0), solve(n - 1, 1) + input[n]);
	if (d == 0)
		ret = max(solve(n - 1, 0) + input[n], input[n]);
	return ret;
}

int main() {
	FAST;
	int tmp;
	cin >> N;
	dp.resize(N, vector<int>(2,NINF));
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}
	int ans = NINF;
	for(int i = N - 1; i >= 0; i--)
	{
		ans = max(ans, solve(i, 0));
		ans = max(ans, solve(i, 1));
	}
	cout << ans;
}

