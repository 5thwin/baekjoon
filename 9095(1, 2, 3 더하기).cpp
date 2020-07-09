#include<cstdio>
#include<string.h>
using namespace std;


int dp[12];
int solve(int n) {
	if (dp[n] != -1)
		return dp[n];
	else
		return dp[n] = solve(n - 3) + solve(n - 2) + solve(n - 1);
}

int main() {
	int T, n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}

}
