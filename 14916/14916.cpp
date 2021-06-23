/*거스름돈*/
#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
typedef long long ll;
using namespace std;

int N;
int main() {
	FAST;
	cin >> N;
	int cost;
	vector<int> dp(N + 1, INF);
	for (cost = 2; cost <= N; cost++)
	{
		if (cost == 5 || cost == 2)
			dp[cost] = 1;
		if (cost % 5 == 0)
			dp[cost] = cost / 5;
		if (cost > 5)
			dp[cost] = min(dp[cost], dp[cost - 5] + 1);
		if (cost > 2)./
			dp[cost] = min(dp[cost], dp[cost - 2] + 1);
	}
	if (dp[N] >= INF)
		cout << "-1\n";
	else
		cout << dp[N] << "\n";
}

