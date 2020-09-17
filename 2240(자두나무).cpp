#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 1000
using namespace std;

int T, W;
int plum[MAX];
int dp[2][MAX][31];
int solve(int pos, int sec, int move) {

	if (sec == T)//기저
		return 0;
	int& ret = dp[pos][sec][move];
	if (ret != -1)
		return ret;

	if(plum[sec] == pos) //현재위치에 떨어질때
	{
		if (move < W) //움직인 경우와 움직이지 않은 경우
			return ret = max(solve(!pos, sec + 1, move + 1), 1 + solve(pos, sec + 1, move));
		//움직이지 못한 경우
		return	ret = 1 + solve(pos, sec + 1, move);
	}
	else { //다른 위치에 떨어질때
		if (move < W) //움직인 경우와 움직이지 않은 경우
			return ret = max(1+ solve(!pos, sec + 1, move + 1), solve(pos, sec + 1, move));
		//움직이지 못한 경우
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