#include<cstdio>
#include<cstring>
#define MOD 1000000000
typedef long long ll;
using namespace std;

ll dp[201][201];
ll solve(int n, int k) {
	ll& ref = dp[n][k];
	ll sum = 0;
	if (ref != -1)
		return ref;
	if (k == 2)
		return ref = (n + 1)%MOD;
	if (k == 1)
		return ref = 1;
	for (int i = 0; i <= n; i++) {
		sum += solve(n - i, k - 1);
		sum %= MOD;
	}
	return ref = sum;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", solve(N, K));

}