#include<cstdio>
#include<cstring>
#include<algorithm>
#define G_MAX 987654321
using namespace std;


int dp[1001];
int arr[1001];
int N;
int solve(int n) {
	int& ret = dp[n];
	if (ret != -1)
		return ret;
	if (n == N)
		return ret = 0;
	if (arr[n] == 0)
		return ret = G_MAX;
	int minval = G_MAX;
	for (int i = 1; i <= arr[n]; i++)
	{
		if (n + i <= N)
			minval = min(minval, solve(n + i));
	}
	return ret = minval + 1;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i + 1);
	}
	int result = solve(1);
	if (result >= G_MAX)
		printf("-1\n");
	else
		printf("%d\n", result);
}
