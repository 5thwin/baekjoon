#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int main() {
	int N, i, j, arr[1000], dp[1000], now, pre, max_val, max_dp = 0;
	/*---input area---*/
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	memset(dp, 0, sizeof(dp));
	/*---solving O(N^2)---*/
	for (i = 0; i < N; i++) {
		now = arr[i];
		max_val = 0;
		for (j = 0; j < i; j++) {
			pre = arr[j];
			if (pre < now) {
				max_val = max(max_val, dp[j]);
			}
		}
		dp[i] = max_val + 1;
		max_dp = max(max_dp, dp[i]);
	}
	printf("%d", max_dp);

}