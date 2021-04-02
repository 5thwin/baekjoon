#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int CMAX = 1e4 + 1;
const int PMAX = 5e2 + 1;
const int INF = 987654321;
int N, M, K; //탭 개수, 목표 CPU, 목표 메모리 할당량
int cp[101], mem[101], pri[101];
int dp[CMAX][PMAX];

int main()
{
	FAST; cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> cp[i] >> mem[i] >> pri[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 1000; j >= 0; j--)
		{
			if (cp[i] > j)
				continue;
			for (int k = 500; k >= 0; k--)
			{
				if (pri[i] > k)
					continue;
				if ((j == cp[i] && k == pri[i]) || dp[j - cp[i]][k - pri[i]])
					dp[j][k] = max(dp[j][k], dp[j - cp[i]][k - pri[i]] + mem[i]);
			}
		}
	}
	int ans = INF;
	for (int i = M; i < CMAX; i++)
	{
		for (int j = 0; j < PMAX; j++)
		{
			if (dp[i][j] >= K)
			{
				ans = min(ans,j);
			}
		}
	}
	cout << (ans == INF ? -1 : ans);
}