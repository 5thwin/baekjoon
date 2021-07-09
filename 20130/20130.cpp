#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

int N, M;
vector<string> map;

vector<pair<int, int> > bfs(int srcy, int srcx)
{
	int dy[4] = {1, -1, 0, 0}; //아래,위,오른쪽,왼쪽
	int dx[4] = {0, 0, 1, -1};
	queue<pair<int, int> > qu;
	vector<pair<int, int> > rec;
	bool visit[200][200]; //방문 여부
	bool isrec[200][200]; //위치 기록 여부
	bool key[26];		  //a-z 키 여부
	memset(visit, 0, sizeof(visit));
	memset(isrec, 0, sizeof(isrec));
	memset(key, 0, sizeof(key));

	qu.push(MP(srcy, srcx));
	visit[srcy][srcx] = 1;
	while (!qu.empty())
	{
		int cy = qu.front().first;
		int cx = qu.front().second;
		qu.pop();
		if (map[cy][cx] >= 'A' && map[cy][cx] <= 'Z') //방문한 점이 key가 있어야 진입이 가능
		{
			if (key[map[cy][cx] - 'A'] == 0) //현재 키를 지니고 있지 않은 경우
			{
				qu.push(MP(cy, cx)); //qu에 다시 집어넣고, 나중에 열쇠를 찾은 후에 방문
				continue;
			}
		}
		if (!isrec[cy][cx]) //현재 위치가 기록되어있지 않은 경우
		{
			isrec[cy][cx] = 1;
			rec.push_back(MP(cy,cx));
		}
		if (map[cy][cx] >= 'a' && map[cy][cx <= 'z']) //현재 지점에 키가 있는 경우
			key[map[cy][cx] - 'a'] = 1;

		for (int i = 0; i < 4; i++) //현재위치에서 4방향 탐색
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx] || map[ny][nx] == '#') //이미 방문한 지점이거나 벽인경우
				continue;
			visit[ny][nx] = 1;
			if (map[ny][nx] == '!') //목표지점에 도달한 경우
			{
				rec.push_back(MP(ny,nx));
				return (rec);
			}
			qu.push(MP(ny, nx));
		}
	}
	return rec;
}
int main()
{
	FAST;
	cin >> N >> M;
	map.resize(N);
	int srcy, srcx;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '@') //시작점 찾기
			{
				srcy = i;
				srcx = j;
			}

		}
	}
	vector<pair<int, int> > rec = bfs(srcy,srcx);
	int len = rec.size();
	cout << len << '\n';
	for (int i = 0; i < len; i++)
	{
		cout << rec[i].first + 1 << " " << rec[i].second + 1 << '\n';
	}
}
