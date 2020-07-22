//DP
#include<cstdio>
#include<cstring>

using namespace std;

long long dp[31][31];
long long solve(int N, int M) {
	long long& ret = dp[N][M];
	if (N == M)
		return ret = 1;
	if (N == 1)
		return ret = M;
	if (dp[N][M] != -1)
		return ret;
	long long result = 0;
	for (int m = N - 1; m <= M - 1; m++) {
		result += solve(N - 1, m);
	}
	return ret = result;
	
}
int main() {
	int T, N, M;
	memset(dp, -1, sizeof(dp));
	dp[1][1] = 1;
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);
		printf("%lld\n",solve(N,M));
	}

}
