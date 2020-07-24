//점화식 세우기
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;

ll dp[101];
ll solve(int N) {
	ll& ret = dp[N];
	if (N == 0) return ret = 0;
	if (N == 1 | N == 2)
		return ret = 1;
	if (dp[N] != -1)
		return ret;
	return ret = solve(N-2) + solve(N - 3);
}
int main() {
	int T,N;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		printf("%lld\n", solve(N));
	}
}