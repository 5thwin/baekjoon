#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

int value[100000][2];
int dp[100000][2];

int solve(int i, int j) {
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i == 0)
		return value[i][j];
	if(j == 1)
		return dp[i][j] = value[i][j] + max(solve(i - 1, j - 1), solve(i - 2, j - 1));
	else
		return dp[i][j] = value[i][j]+ max(solve(i - 1, j + 1), solve(i - 2, j + 1));
}
int main() {
	int T,n;
	scanf("%d", &T);
	for (int tc = 0; tc <T; tc++) {
		scanf("%d", &n);
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &value[j][i]);
			}
		}
		memset(dp, -1, sizeof(dp));
		int ans = max(solve(n - 1, 0), solve(n - 1, 1));
		printf("%d\n",ans);
	}

}