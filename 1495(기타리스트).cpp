#include<cstdio>
#include<cstring>
using namespace std;

int v[100];
bool dp[101][1001]; // º¼·ý 0~1000
int main() {
	int N, S, M, i, j;
	scanf("%d %d %d", &N, &S, &M);
	dp[0][S] = 1;
	for (i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j <= M; j++) {
			if (!dp[i][j])
				continue;
			if (j + v[i] <= M)
				dp[i + 1][j + v[i]] = 1;
			if (j - v[i] >= 0)
				dp[i + 1][j - v[i]] = 1;
		}
	}
	//for (i = 0; i <= M; i++) {
	//	printf("%d ",dp[N][i]);
	//}
	for (i = M; i >= 0; i--) {
		if (dp[N][i] != 0)
		{
			printf("%d\n", i);
			break;
		}
	}
	if (i < 0)
		printf("-1\n");
}