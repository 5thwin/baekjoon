#include<cstdio>
#include<cstring>
#define MOD 10007
using namespace std;

int dp[1001][1001];
int solve(int N, int K) {
	int& ret = dp[N][K];
		
	if (N == 1 || K == N || K == 0)
		return ret = 1;
	if (ret != -1)
		return ret;
	return ret = (solve(N - 1, K ) + solve(N - 1, K -1)) % MOD;
}
int main() {
	int N, K;
	memset(dp, -1, sizeof(dp));
	scanf("%d %d" ,&N, &K);
	printf("%d", solve(N, K));
}