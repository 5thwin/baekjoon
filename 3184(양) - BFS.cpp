#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int R, C;
vector<string> map;
bool visit[251][251];
pair<int, int> BFS(int y, int x) {
	int sheep = 0, wolf = 0;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	queue<pair<int, int>> qu;
	qu.push(MP(y, x));
	while (!qu.empty())
	{
		int cy = qu.front().first;
		int cx = qu.front().second;
		qu.pop();
		if (visit[cy][cx])
			continue;
		visit[cy][cx] = 1;
		if (map[cy][cx] == 'o')
			sheep++;
		else if (map[cy][cx] == 'v')
			wolf++;
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= R || nx >= C || ny < 0 || nx < 0)
				continue;
			if (map[ny][nx] == '#')
				continue;
			if (visit[ny][nx])
				continue;
			qu.push(MP(ny, nx));
		}
	}
	return (MP(sheep, wolf));
}
int main()
{
	FAST; 
	int total_sheep = 0, total_wolf = 0;
	pair<int, int> pr;
	cin >> R >> C; //R : 세로 C : 가로길이
	map.resize(R);
	for (int i = 0; i < R; i++)
		cin >> map[i];
	for (int c = 0; c < R; c++)
	{
		for (int r = 0; r < C; r++)
		{ 
			if (!visit[c][r])
			{
				pr = BFS(c, r);
				if (pr.first > pr.second)
					total_sheep += pr.first;
				else
					total_wolf += pr.second;
			}
		}
	}
	cout << total_sheep << " " << total_wolf;
}
