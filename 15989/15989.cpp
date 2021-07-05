#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int dp[10001][4]; //dp[n][k] : k와 k보다 작거나 같은 수들의 덧셈으로 n을 만드는 방법의 수

int solve(int n, int k)
{
	if (n <= 0 || n < k)
		return 0;
	int &ret = dp[n][k];
	if (ret != -1)
		return ret;
	if (n == 1)
		return ret = 1;
	if (n == k)
		return ret = 1;
	if (k == 1)
		ret = solve(n - 1, 1);
	if (k == 2)
		ret = solve(n - 2, 2) + solve(n - 2, 1);
	if (k == 3)
		ret = solve(n - 3, 3) + solve(n - 3, 2) + solve(n - 3, 1);
	return ret;

}
int main() {
	FAST;
	int T, n;
	memset(dp, -1, sizeof(dp));
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << solve(n, 1) + solve(n, 2) + solve(n, 3) << "\n";
	}
}

