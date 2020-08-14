#include<cstdio>
#include<cstring>
using namespace std;

int dp[15][15];
int N, M, K;

int solve(int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	int& ref = dp[y][x];
	if (ref != 0)
		return ref;
	if (x == 0 && y == 0)
		return ref = 1;
	return ref = solve(x - 1, y) + solve(x, y - 1);
}
int main() {
	int x, y;
	scanf("%d %d %d", &N, &M, &K); //N 세로, M 가로
	if (K == 0)
	{
		printf("%d\n", solve(M - 1, N - 1));
	}
	else {
		y = (K-1) / M;
		x = (K - 1) % M;
		int result = solve(x, y) * solve(M - x-1, N - y-1);
		printf("%d\n",result);
	}
}