#include<cstdio>
#include<cstring>
using namespace std;

int map[16][16];
int dp[3][16][16];
int solve(int k, int c, int r) { // k = 0 가로, 1 세로, 2 대각선
	if (c < 0 || r < 0)
		return 0;
	int& ref = dp[k][c][r];
	if (ref != -1)
		return ref;
	if (c == 0 && r == 1 && k == 0)
		return ref = 1;
	if (r <= 1)
		return ref = 0;
	if (map[c][r] == 1)
		return ref = 0;
	if ((k == 1 || k == 2) && c == 0)
		return ref = 0;
	if (k == 0 && r == 2 && c != 0)
		return ref = 0;
	
	if (k == 0) {
		return ref = solve(0, c, r - 1) + solve(2, c, r - 1);
	}
	if (k == 1) {
		return ref = solve(1, c - 1, r) + solve(2, c - 1, r);
	}
	if (k == 2) {
		if (map[c - 1][r] + map[c][r - 1] != 0) //빈칸이어야 함
			return ref = 0;
		return ref = solve(0, c - 1, r - 1) + solve(1, c - 1, r - 1) + solve(2, c - 1, r - 1);
	}

}
int main() {
	int N;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	int result = solve(0, N - 1, N - 1) + solve(1, N - 1, N - 1) + solve(2, N - 1, N - 1);

	printf("%d", result);
}