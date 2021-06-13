/*치즈*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
using namespace std;

int N, M;//세로 가로
vector<vector<int> > map;
int bfs()
{
	queue<pair<int, int> > qu;
	stack<pair<int, int> > melt;
	vector<vector<bool> > visit(N, vector<bool>(M, 0));
	int dy[4] = {-1, 0, 1, 0}; //북, 동, 남, 서
	int dx[4] = {0, 1, 0, -1};
	qu.push(MP(0, 0));
	visit[0][0] = 1;
	while (!qu.empty())
	{
		int cy = qu.front().first;
		int cx = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx])
				continue;
			visit[ny][nx] = 1;
			if (map[ny][nx] == 0)
				qu.push(MP(ny, nx));
			else
				melt.push(MP(ny, nx));
		}
	}
	int ret = melt.size();
	while(!melt.empty())
	{
		int cy = melt.top().first;
		int cx = melt.top().second;
		melt.pop();
		map[cy][cx] = 0;
	}
	return ret;
}

int main() {
	FAST;
	int input, remain = 0;
	cin >> N >> M;
	map.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> input;
			remain += input;
			map[i][j] = input;
		}
	}
	int time = 0, ret;
	while ((ret = bfs()) > 0)
	{
		time++;
		remain -= ret;
		if (remain == 0)
		{
			cout << time << '\n' << ret;
			break;
		}
	}
}

