#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MP make_pair
using namespace std;

int N;
bool map[25][25];
bool visit[25][25];
int BFS(int i, int j)
{
	int vsize = 0;
	int di[4] = { -1, 1, 0, 0 };
	int dj[4] = { 0, 0, -1, 1 }; //위, 아래, 왼쪽, 오른쪽
	queue<pair<int,int>> qu;
	qu.push(MP(i, j));
	while (!qu.empty())
	{
		int curi = qu.front().first;
		int curj = qu.front().second;
		qu.pop();
		if (visit[curi][curj] == 1)
			continue;
		vsize++;
		visit[curi][curj] = 1;
		for (int i = 0; i < 4; i++)
		{
			int ni = curi + di[i];
			int nj = curj + dj[i];
			if (ni >= N || nj >= N || ni < 0 || nj < 0)
				continue;
			if (visit[ni][nj] == 0 && map[ni][nj] == 1)
				qu.push(MP(ni, nj));
		}
	}
	return vsize;
}
int main()
{
	priority_queue<int> pqu;
	cin >> N;
	char input[26];
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < N; j++)
			map[i][j] = (bool)(input[j] - '0');
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0)
				continue;
			if (visit[i][j] == 1)
				continue;
			pqu.push(-1 * BFS(i, j));
		}
	}
	cout << pqu.size() << "\n";
	while (!pqu.empty())
	{
		cout << -1 * pqu.top() << "\n";
		pqu.pop();
	}
}