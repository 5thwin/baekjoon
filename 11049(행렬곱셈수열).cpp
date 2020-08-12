#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 4294967295
typedef long long ll;
using namespace std;

int N;
int dim[501];
ll dp[501][501];
ll solve(int s, int e) {
	ll& ref = dp[s][e];
	if (ref != -1)
		return ref;
	if (s + 1 == e)
		return ref = 0;
	ll minval = MAX;
	for (int i = s+1; i < e; i++) {
		minval = min( minval, solve(s, i) + solve(i, e) + dim[s] * dim[i] * dim[e]);
	}
	return ref = minval;
}
int main() {
	scanf("%d", &N);
	int r, c;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &r, &c);
		dim[i] = r;
		if (i == N - 1)
			dim[N] = c;
	}

	printf("%lld", solve(0, N));
}