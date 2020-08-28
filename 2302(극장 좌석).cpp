#include<cstdio>
#include<cstring>
using namespace std;

int N, M;
bool S[41];
int dp[41];
int solve(int n) {

	int& ret = dp[n];
	if (ret != 0)
		return ret;
	if (n == 1)
		return ret = 1;
	if (n == 0)
		return ret = 1;

	if (S[n])
		return ret = solve(n - 1);
	if (S[n - 1])
		return ret = solve(n - 1);
	return ret = solve(n - 1) + solve(n - 2);
}
int main() {
	memset(dp, 0, sizeof(dp));
	scanf("%d %d", &N, &M);
	int solid;
	for (int i = 0; i < M; i++) {
		scanf("%d", &solid);
		S[solid] = true;
	}
	printf("%d\n", solve(N));
	
}