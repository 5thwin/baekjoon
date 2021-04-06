#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<string> map;
bool visit[100][100];
int BFS(int y, int x,char color, bool weekness)
{
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	queue < pair<int, int>> qu;
	qu.push(MP(y, x));
	while (!qu.empty())
	{
		int cy = qu.front().first;
		int cx = qu.front().second;
		qu.pop();
		if (visit[cy][cx])
			continue;
		visit[cy][cx] = 1;
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (!weekness && color != map[ny][nx])
				continue;
			if (weekness && (color == 'B' || map[ny][nx] == 'B') && color != map[ny][nx])
				continue;
			if (visit[ny][nx])
				continue;
			qu.push(MP(ny, nx));
		}
	}
	return (1);
}
int main()
{
	FAST;
	int section1 = 0, section2 = 0;
	cin >> N;
	map.resize(N);
	for (int i = 0; i < N; i++)
		cin >> map[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j])
				continue;
			if (BFS(i, j, map[i][j], 0))
				section1++;
		}
	}
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j])
				continue;
			if (BFS(i, j, map[i][j], 1))
				section2++;
		}
	}
	cout << section1 << " " << section2;
}