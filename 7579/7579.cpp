#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair;
#define INF 99999999;
#define NINF -INF;
typedef long long ll;
using namespace std;

int dp[100][10001];
// dp[index][cost] : 0~index번째 앱 중에서 cost비용을 들여 일부 앱을 비활성화 시켰을 때, 최대로 확보할 수 있는 메모리
// 정답을 탐색하려면 dp[N][0~100]을 탐색하여 M보다 크거나 같은 값 중 첫번째를 탐색한다.
int N, M;
void insertInput();
void printOutput();

struct App
{
	int memmory, cost;
	App()
	{
		memmory = NINF;
		cost = INF;
	}
};
App app[100];

int solve(int i, int c)
{
	if (c < 0)
		return NINF;
	if (i < 0)
		return 0;
	int &ref = dp[i][c];
	if (ref != -1)
		return ref;
	// app[i]를 비활성화하는 경우와 남기는 경우 중 메모리 확보가 큰 것을 선택
	return ref = max(solve(i - 1, c - app[i].cost) + app[i].memmory, solve(i - 1, c));
}

int main()
{
	FAST;
	insertInput();
	memset(dp, -1, sizeof(dp));
	// sort(app, app + N, compare);
	printOutput();
}

void insertInput()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> app[i].memmory;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> app[i].cost;
	}
}

void printOutput()
{

	for (int curCost = 0; curCost < 10001; curCost++)
	{
		int curMem = solve(N - 1, curCost);
		if (curMem >= M)
		{
			cout << curCost;
			return;
		}
	}
}
