#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;

int N, table[101][101];
ll dp[101][101];

ll solve(int n, int m) {
	ll& ret = dp[n][m];
	if (ret != -1)
		return ret;
	if (n == N && m == N) {
		return ret = 1;
	}
	if (n > N || m > N)
		return 0;
	if (table[n][m] == 0)
		return 0;
	return ret = solve(n + table[n][m], m) + solve(n, m + table[n][m]);
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &table[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld", solve(1, 1));
}