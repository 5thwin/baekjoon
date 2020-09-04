#include<cstdio>
#include<cstring>
using namespace std;

int N, M;
int coin[20];
int dp[10001];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d" ,&N);
		for (int i = 0; i < N; i++) {
			scanf("%d", coin + i);
		}
		scanf("%d", &M);
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int cost = 1; cost <= M; cost++) {
				if (cost < coin[i])
					continue;
				dp[cost] += dp[cost - coin[i]];
			}
		}
		printf("%d\n", dp[M]);
	}
}