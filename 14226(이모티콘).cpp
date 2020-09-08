#include<cstdio>
#include<queue>
#include<cstring>
#define INF 987654321
using namespace std;

/*
������ ���
1.Ŭ�����忡 ����
2.Ŭ�����带 ȭ�鿡 �߰�
3.�Ѱ� ����
*/
int dp[1001][1001]; //dp[ȭ��][Ŭ������]
queue<pair<int, int>> qu;
void bfs_solve(int dest) {
	pair<int,int> cur;
	int cv, cc, nv, nc;
	dp[1][0] = 0;
	qu.push({ 1,0 });
	while (!qu.empty()) {
		cur = qu.front();
		qu.pop();
		cv = cur.first;
		cc = cur.second;
		/*1 Ŭ������ ����*/
		nv = cv, nc = cv;
		if (dp[nv][nc] == -1 || dp[nv][nc] > dp[cv][cc] + 1)
		{
			dp[nv][nc] = dp[cv][cc] + 1;
			qu.push({ nv,nc });
		}
		/*Ŭ������ ������ ȭ�鿡 �߰�*/
		nv = cv + cc, nc = cc;
		if (nv > 1000 || nv > dest);
		else if (dp[nv][nc] == -1 || dp[nv][nc] > dp[cv][cc] + 1) {
			dp[nv][nc] = dp[cv][cc] + 1;
			qu.push({ nv,nc });
		}
		/*ȭ�� �̸�Ƽ�� �� �� ����*/
		nv = cv - 1, nc = cc;
		if (nv < 0);
		else if (dp[nv][nc] == -1 || dp[nv][nc] > dp[cv][cc] + 1)
		{
			dp[nv][nc] = dp[cv][cc] + 1;
			qu.push({ nv,nc });
		}

	}
	

}
int main() {
	int N;
	scanf("%d",&N);
	memset(dp, -1, sizeof(dp));
	bfs_solve(N);
	int ans = INF;
	for (int i = 0; i < N; i++) {
		if (dp[N][i] == -1)
			continue;
		ans = min(ans, dp[N][i]);
	}
	printf("%d\n", ans);
}