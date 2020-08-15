//가장 증가하는 부분수열로 접근
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int cache[200];
int dp[200];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", cache + i);
	}
	int LIS = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (cache[j] < cache[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		LIS = max(LIS, dp[i]);
	}
	printf("%d", N - LIS);
}