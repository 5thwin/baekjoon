#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 1000
using namespace std;

int T, W;
int plum[MAX];
int dp[2][MAX][31];
int solve(int pos, int sec, int move) {

	if (sec == T)//����
		return 0;
	int& ret = dp[pos][sec][move];
	if (ret != -1)
		return ret;

	if(plum[sec] == pos) //������ġ�� ��������
	{
		if (move < W) //������ ���� �������� ���� ���
			return ret = max(solve(!pos, sec + 1, move + 1), 1 + solve(pos, sec + 1, move));
		//�������� ���� ���
		return	ret = 1 + solve(pos, sec + 1, move);
	}
	else { //�ٸ� ��ġ�� ��������
		if (move < W) //������ ���� �������� ���� ���
			return ret = max(1+ solve(!pos, sec + 1, move + 1), solve(pos, sec + 1, move));
		//�������� ���� ���
		return	ret = solve(pos, sec + 1, move);
	}
}
int main() {
	scanf("%d %d", &T, &W);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < T; i++) {
		scanf("%d", &plum[i]);
		plum[i]--;
	}
	printf("%d\n", solve(0, 0, 0));
}