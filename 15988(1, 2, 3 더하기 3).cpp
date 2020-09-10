#include<cstdio>
#include<cstring>
#define MOD 1000000009
typedef long long ll;
using namespace std;

ll dp[1000001];
ll solve(int n) {
	ll& ret = dp[n];
	if (ret != 0)
		return ret;
	if (n == 1)
		return ret = 1;
	if (n == 2)
		return ret = 2;
	if (n == 3)
		return ret = 4;

	return ret = ( solve(n - 1) + solve(n - 2) + solve(n - 3) ) % MOD;
}
int main() {
	int T,N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", solve(N));
	}
}