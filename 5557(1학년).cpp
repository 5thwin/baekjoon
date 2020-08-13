#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
int N;
int cache[100];
ll dp[100][21];

int main() {
	scanf("%d", &N);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; i++) {
		scanf("%d", &cache[i]);
	}
	dp[0][cache[0]] = 1;
	for (int n = 1; n < N-1; n++) {
		for (int i = 0; i < 21; i++) {
			if (dp[n - 1][i] == 0) //�����ܰ迡�� 0�̾����� ��ŵ
				continue;
			if (i + cache[n] < 21) //�����ܰ���� ��꿡 �� ���� ���Ѱ� 20 ����
				dp[n][i + cache[n]] += dp[n - 1][i];
			if (i - cache[n] >= 0) //�����ܰ���� ��꿡 �� ���� �� ���� 0 �̻�
				dp[n][i - cache[n]] += dp[n - 1][i];
		}
	}
	printf("%lld\n", dp[N - 2][cache[N - 1]]);
}
