#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 987654321
using namespace std;


int N, M;
int map[1000][1000];
int dp[1000][1000][3]; //3-> 0:���ʿ��� �� ���, 1:�����ʿ��� �� ���, 2:������ �Ʒ��� �� ���,

int solve(int n, int m, int from) {
	if (n < 0 || m < 0 || n >= N || m >= M)
		return -INF;
	int& ret = dp[n][m][from];
	if (ret != -INF)
		return ret;
	if (n == 0 && m == 0)
		return ret = map[n][m];
	
	if (from == 0) { //���ʿ��� �� ���, �����ܰ�� �����ʿ��� �� ��츦 ����
		return ret = map[n][m] + max(solve(n, m - 1, 0), solve(n, m - 1, 2));
	}
	if (from == 1) { //�����ʿ��� �� ���, �����ܰ�� ���ʿ��� �� ��츦 ����
		return ret = map[n][m] + max(solve(n, m + 1, 1), solve(n, m + 1, 2));
	}
	if (from == 2) { //������ �� ���, �����ܰ�� �� ���� ��� ���
		return ret = map[n][m] + max( max(solve(n-1, m, 0), solve(n-1, m, 1)) ,solve(n-1,m,2) );
	}
}
int main() {
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = -INF;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n", max(solve(N - 1, M - 1,0), solve(N-1,M-1,2)));
}