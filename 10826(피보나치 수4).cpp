//큰수의 출력 방법 (+새로 이름만 알게된 카라추바 알고리즘)
#include<cstdio>
#define MAXSIZE 100000000
using namespace std;

int dp[10001][1000];

int main() {
	int N;
	scanf("%d", &N);
	dp[0][0] = 0;
	dp[1][0] = 1;
	for (int i = 2; i <= N; i++) {
		for (int cnt = 0; cnt < 1000; cnt++) {
			dp[i][cnt] = dp[i - 1][cnt] + dp[i - 2][cnt];
			if (dp[i - 1][cnt] == 0 && dp[i - 2][cnt] == 0)
				break;
		}
		for (int cnt = 1; cnt < 1000; cnt++) {
				dp[i][cnt] += dp[i][cnt - 1] / MAXSIZE;
				dp[i][cnt - 1] %= MAXSIZE;
		}

	}
	bool flg = 0;
	for (int cnt = 999; cnt >= 0; cnt--) {
		if (!flg) { //최고자리 결정 안남
			if (dp[N][cnt] > 0 || cnt == 0)
			{
				printf("%d", dp[N][cnt]);
				flg = 1;//최고자리 결정
			}
		}
		else {
			printf("%08d", dp[N][cnt]);
		}
	}



}