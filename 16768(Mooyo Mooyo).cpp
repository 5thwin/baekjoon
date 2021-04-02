#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define MP make_pair
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int N, K;
char map[101][10];
bool visit[101][10];
queue<pair<int, int>> zeroqu;
void print_map()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << map[i][j];
		}cout << "\n";
	}
}
int BFS(int posi, int posj, char color)
{
	int di[4] = { -1, 1, 0, 0 };
	int dj[4] = { 0, 0, -1, 1 }; //위, 아래, 왼쪽, 오른쪽
	queue<pair<int, int>> qu;
	int adj_size = 0;
	qu.push(MP(posi, posj));
	while (!qu.empty())
	{
		int nowi = qu.front().first;
		int nowj = qu.front().second;
		qu.pop();
		if (visit[nowi][nowj])
			continue;
		visit[nowi][nowj] = 1;
		zeroqu.push(MP(nowi, nowj));
		adj_size++;
		for (int i = 0; i < 4; i++)
		{
			int nexti = nowi + di[i];
			int nextj = nowj + dj[i];
			if (nexti < 0 || nextj < 0 || nexti >= N || nextj >= 10)
				continue;
			if (visit[nexti][nextj])
				continue;
			if (map[nexti][nextj] != color)
				continue;
			qu.push(MP(nexti, nextj));
		}
	}
	return (adj_size);
}
void drop()
{
	for (int j = 0; j < 10; j++)
	{
		int drop_pos = N - 1;
		for (int i = N - 1; i >= 0; i--)
		{
			if (map[i][j] == '0')
				continue;
			else if (drop_pos == i)
				drop_pos--;
			else
			{
				map[drop_pos][j] = map[i][j];
				map[i][j] = '0';
				drop_pos--;
			}
		}
	}
}
int main()
{
	int zri, zrj;
	bool is_removed = 0;
	FAST; cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	while (1)
	{
		is_removed = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (map[i][j] == '0')
					continue;
				if (visit[i][j])
					continue;
				if (BFS(i, j, map[i][j]) >= K)
				{
					while (!zeroqu.empty())
					{
						zri = zeroqu.front().first;
						zrj = zeroqu.front().second;
						zeroqu.pop();
						map[zri][zrj] = '0';
					}
					is_removed = 1;
				}
				/*zeroqu 비우기*/
				while (!zeroqu.empty())
					zeroqu.pop();
			}
		}
		if (is_removed)
			drop();
		if (!is_removed)
			break;
	}
	print_map();
}
