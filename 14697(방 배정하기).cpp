#include<cstdio>

using namespace std;

int N, room[3];
int dp[301];
int main() {
	scanf("%d %d %d %d", &room[0], &room[1], &room[2], &N);
	for (int i = 0; i < 3; i++) {
		for (int n = 0; n <= N; n++) {
			if (n == 0)
			{
				dp[n] = 1;
				continue;
			}
			if (n - room[i] >= 0)
			{
				dp[n] += dp[n - room[i]];
			}
		}
	}
	if (dp[N])
		printf("1\n");
	else
		printf("0\n");
}