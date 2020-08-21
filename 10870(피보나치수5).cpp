#include<cstdio>

using namespace std;

int dp[21];
int main() {
	int N;
	dp[0] = 0; dp[1] = 1;
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%d", dp[N]);
}