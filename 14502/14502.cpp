#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

int N, M;
vector<pair<int, int> > virus; //바이러스의 위치
int vcnt = 0; //바이러스의 개수, 바이러스가 아직 안퍼진 공간
int max_safe = -1;
int bfs_infect(vector<vector<int> > map)
{
	int dy[4] = {0, 0, 1, -1}; //동서남북
	int dx[4] = {1, -1, 0, 0};
	int safe = 0; //안전영역
	for (int i = 0; i < vcnt; i++)
	{
		int vy = virus[i].first;
		int vx = virus[i].second;
		queue<pair<int, int> > qu;
		qu.push(MP(vy,vx));
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
				if (map[ny][nx] != 0)
					continue;
				map[ny][nx] = 2; //감염됨
				qu.push(MP(ny,nx));
			}
		}
	}
	//모든 바이러스가 도달할 수 있는 곳은 모두 감염된 후, 남은 0 세기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
				safe++;
		}
	}
	return safe;
}
//재귀함수를 통해 벽을 세울수 있는 모든 경우에 대해 탐색
void setwall(vector<vector<int> > map, int py, int px, int order)
{
	if (order == 3) //벽을 모두 세움
	{
		max_safe = max(max_safe, bfs_infect(map));
		return ;
	}
	int sy = py, sx;
	//py, px 이전에 벽을 세운 위치
	for (int y = sy; y < N; y++)
	{
		sx = ((y == sy) ? px + 1 : 0); //이전에 벽을 세운 위치의 다음부터 탐색
		for (int x = sx; x < M; x++)
		{
			if (map[y][x] != 0)
				continue;
			map[y][x] = 1;
			setwall(map, y, x, order + 1);
			map[y][x] = 0;
		}
	}
}
int main() {
	FAST;
	vector<vector<int> > map;
	cin >> N >> M;
	map.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				vcnt++;
				virus.push_back(MP(i,j));
			}
		}
	}

	//브루트포스로 벽 세우기
	setwall(map, 0, -1, 0);
	cout << max_safe << "\n";
}

