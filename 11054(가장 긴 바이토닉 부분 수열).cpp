#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[1001], dp[1001], rdp[1001];

int main() {
	int N, n ,ren;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i + 1]);
	}
	dp[1] = rdp[N] = 1;
	for (n = 2; n <= N; n++) {
		ren = N + 1 - n;
		dp[n] = rdp[ren] = 1;
		for (int i = 1, rei = N; i < n; i++, rei--) {
			
			if (arr[i] < arr[n]){
				dp[n] = max(dp[i] + 1, dp[n]);
			}
			if (arr[rei] < arr[ren]) {
				rdp[ren] = max(rdp[rei] + 1, rdp[ren]);
			}
		}
	}
	//for (int i = 1; i <= N; i++) {
	//	printf("%d ", dp[i]);
	//}printf("\n");
	//for (int i = 1; i <= N; i++) {
	//	printf("%d ", rdp[i]);
	//}printf("\n");
	int max_len = 0;
	for (int i = 1; i <= N; i++) {
		max_len = max(max_len, dp[i] + rdp[i]-1);
	}
	printf("%d\n", max_len);
}