#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair
#define INF 1e9

typedef long long ll;
using namespace std;

int N, D[20][20];
int dp[20][1 << 21]; // dp[n][flag] : 0~i번째 사람이 일을 하나씩 선택하여 일이 할당 상태가 flag일때, 최소 비용
int flag;			 //바트마스킹 : flag | 1 << a  = a번째 일을 할당함
// DFS로 탐색을 해는데, 1-2-3-4 조합이나 1-2-4-3  조힙에서 1,2는 같으니까 이를 dp[1][0011]에서 꺼내 쓰자
int dfs(int n, int flag)
{
	if (n == N)
		return 0;
	if (dp[n][flag] != -1)
		return dp[n][flag];
	dp[n][flag] = INF;
	for (int k = 0; k < N; k++)
	{ // n번 사람이 k번째 일을 선택하려 합니다.
		if (flag & 1 << k)
			continue; //만약 그 일이 처리되었으면 스킵

		dp[n][flag] = min(dp[n][flag], dfs(n + 1, flag | 1 << k) + D[n][k]);
	}
	return dp[n][flag];
}

int main()
{
	FAST;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> D[i][j];
		}
	}
	// solve
	flag = 0;
	cout << dfs(0, 0);
}
