#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int n, m, table[1001][1001];
int dp[1001][1001];
int solve(int i, int j) {// 정사각형 한 변을 리턴(왼쪽 위 모서리를 i,j 위치했을 떄)

	if (i > n || j > m)
		return 0;
	int& ref = dp[i][j];
	if (ref != -1)
		return ref;
	int down = solve(i + 1, j), right = solve(i, j + 1);
	if (table[i][j] == 0)
		return ref = 0;
	
	if (down == 0 || right == 0)
		return ref = 1;
	int sq = min(down, right);
	if (table[i + sq][j + sq] == 1)
		return ref = sq + 1;
	return ref = sq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		for (int j = 1; j <= m; j++) {
			table[i][j] = input[j - 1] - '0';
		}
	}
	solve(1, 1);
	int maxsz = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			maxsz = max(maxsz, dp[i][j]);
		}
	}
	cout << maxsz*maxsz;
}