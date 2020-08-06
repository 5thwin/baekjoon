//굳이 dp로 풀어야 할까
#include<cstdio>
#include<cstring>

using namespace std;
int dp[101];
int solve(int n) {
	int& ref = dp[n];
	int temp = 0;
	if (ref != 0)
		return ref;
	if (n == 1)
		return 1;
	for (int i = 1; i * i <= n; i++) {
		if (i * i == n)
			temp = 1;
	}
	return ref = solve(n - 1) + temp;
}
int main() {
	int T,n;
	scanf("%d", &T);
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	while (T--)
	{
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
}