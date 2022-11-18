#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair
#define CtoI(X) (X - '0')
#define INF 99999999
#define NINF -INF

typedef long long ll;
using namespace std;
// dfs와 dp의 혼합 문제
vector<string> area;
int N, M;
int dp[51][51][4]; // dp[[y][x][d] : y,x위치에서 d방향으로 갔을 때, 최대로 할 수 있는 게임의 수
bool isVisit[51][51][4];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

//먼저 dfs를 통해 싸이클을 생성하는 지 확인

// py, px에서 d방향으로 갔을 때, 최대로 움직일 수 있는 횟수를 리턴
int solve(int py, int px, int d)
{
	int cy = py + dy[d] * CtoI(area[py][px]);
	int cx = px + dx[d] * CtoI(area[py][px]);
	//현재 위치가 범위 밖이거나 구멍이면 더 이상 게임할 수 없으므로  0 리턴
	if (cy < 0 || cx < 0 || cy >= N || cx >= M)
		return 0;
	int &ref = dp[py][px][d];
	if (ref != -1)
		return ref;
	if (area[cy][cx] == 'H')
		return ref = 0;
	if (isVisit[py][px][d]) //사이클 존재
	{
		return ref = INF;
	}
	isVisit[py][px][d] = true;
	int movement = 0;
	for (int i = 0; i < 4; i++)
	{
		int next = solve(cy, cx, i);
		if (next == INF)
			return ref = INF;
		movement = max(movement, next);
	}
	return ref = movement + 1;
}

int main()
{
	FAST;
	cin >> N >> M;
	area.resize(N);
	for (int i = 0; i < N; i++)
		cin >> area[i];
	memset(dp, -1, sizeof(dp));
	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		answer = max(answer, solve(0, 0, i));
	}
	if (answer == INF)
		cout << -1;
	else
		cout << answer + 1;
}
