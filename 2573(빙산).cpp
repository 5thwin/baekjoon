#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> melt;
int adj_zero(int n, int m)
{
	int ret = 0;
	/*북*/
	if (n - 1 >= 0)
		ret += (map[n - 1][m] == 0) ? 1 : 0;
	/*남*/
	if (n + 1 < N)
		ret += (map[n + 1][m] == 0) ? 1 : 0;
	/*동*/
	if (m + 1 < M)
		ret += (map[n][m + 1] == 0) ? 1 : 0;
	/*서*/
	if (m - 1 >= 0)
		ret += (map[n][m - 1] == 0) ? 1 : 0;
	return ret;
}
pair<int, int> ft_start()
{
	int start_c, start_r;
	for (start_c = 0; start_c < N; start_c++)
	{
		for (start_r = 0; start_r < M; start_r++)
		{
			if (map[start_c][start_r] > 0)
				return make_pair(start_c, start_r);
		}
	}
	return make_pair(-1, -1);
}
int bfs()
{
	int visit_cnt = 0;
	int mv_c[4] = { -1, 1, 0, 0 };
	int mv_r[4] = { 0, 0, -1, 1 };
	int cc, cr, nc, nr;

	pair<int, int> start;
	vector<vector<bool>> visit;
	queue<pair<int, int>> qu;
	start = ft_start();
	if (start.first < 0)
		return (-1);
	visit.resize(N, vector<bool>(M, 0));
	qu.push(start);
	while (!qu.empty())
	{
		cc = qu.front().first, cr = qu.front().second;
		qu.pop();
		if (visit[cc][cr] == 1)
			continue;
		visit_cnt++;
		visit[cc][cr] = 1;
		melt[cc][cr] = adj_zero(cc, cr);
		for (int i = 0; i < 4; i++)
		{
			nc = cc + mv_c[i];
			nr = cr + mv_r[i];
			if (nc < 0 || nc >= N || nr < 0 || nr >= M)
				continue ;
			if (visit[nc][nr] == 1 || map[nc][nr] == 0)
				continue;
			qu.push(make_pair(nc, nr));
		}
	}
	return visit_cnt;
}

int melting()
{
	int no_zero = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] =(map[i][j] > melt[i][j]) ? (map[i][j] - melt[i][j]) : 0;
			no_zero += (map[i][j] != 0) ? 1 : 0;
			melt[i][j] = 0;
		}
	}
	return no_zero;
}
void print_map()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}
int main()
{
	int i, j, input, no_zero = 0;
	int year = 0;

	scanf("%d %d", &N, &M);
	map.resize(N, vector<int>(M));
	melt.resize(N, vector<int>(M, 0));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &input);
			map[i][j] = input;
			if (input != 0)
				no_zero++;
		}
	}
	while (1)
	{
		if (bfs() != no_zero)
			break;
		no_zero = melting();
		if (no_zero == 0) //녹았더니 빙하가 남아있지 않음 -> 분리되지 않음
		{
			year = 0;
			break;
		}
		year++;
	}
	printf("%d\n", year);
}