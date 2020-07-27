#include<cstdio>
#include<cstring>
using namespace std;

int dp[301][301];
int table[301][301];
int solve(int x, int y) {
	int& ref = dp[x][y];
	if (x == 0 || y == 0)
		return ref = 0;
	if (ref != -1)
		return ref;
	return ref = table[x][y] + solve(x - 1, y) + solve(x, y - 1) - solve(x - 1, y - 1);
		
}
int main() {
	int N, M, K,i,j,x,y, result;
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			scanf("%d", &table[n][m]);
		}
	}
	memset(dp, -1, sizeof(dp));
	scanf("%d", &K);
	while (K--) {
		scanf("%d %d %d %d", &i, &j, &x, &y);
		result = solve(x, y) -solve(i-1,y) - solve(x,j-1) + solve(i - 1, j - 1);
		printf("%d\n", result);
	}
}