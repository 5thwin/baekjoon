//LIS ±¸ÇÏ±â
#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int dp[1001];
int main() {
	int box[1001], max_len=1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &box[i]);
	}
	dp[0] = 1;
	for (int here = 1; here < N; here++) {
		dp[here] = 1;
		for (int pre = 0; pre < here; pre++) {
			if (box[here] > box[pre]) {
				dp[here] = max(dp[here], dp[pre] + 1);
			}
		}
		max_len = max(max_len, dp[here]);
	}
	printf("%d", max_len);
}