//DP Á¡È­½Ä
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
ll dp[31];
ll solve(int N) {
	ll& ret = dp[N];
	ll sum = 0;
	if (N == 0)
		return ret = 1;
	if (N % 2) //È¦¼ö
		return ret = 0;
	if (N == 2)
		return ret = 3;
	if (ret != -1)
		return ret;
	for (int i = 0; i < N; i += 2) {
		sum += 2 * solve(i);
	}
	return ret = sum +  solve(N - 2);
}
int main() {
	int N;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%lld", solve(N));
}