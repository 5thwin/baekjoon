#include<cstdio>
#include<cstring>
#include<algorithm>>
#include<vector>
#define INF 987654321
using namespace std;

int N, M;
int m[100], c[100];
int dp[100][10001]; // dp[i][cost] =i번째어플 cost에서 최대로 획득할 수 있는 메모리


int main() {
	memset(dp, 0, sizeof(dp));
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &m[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &c[i]);
	}
	int mincost = INF;
	dp[0][c[0]] = m[0];
	for (int i = 1; i < N; i++) {
		for (int cost = 0; cost < 10001; cost++) {
			if (cost - c[i] >= 0) {
				dp[i][cost] = max(dp[i][cost], dp[i-1][cost - c[i]] + m[i]);
			}
			dp[i][cost] = max(dp[i - 1][cost], dp[i][cost]);

			if (dp[i][cost] >= M) {
				mincost = min(mincost, cost);
			}
		}
	}
	printf("%d\n", mincost);
}