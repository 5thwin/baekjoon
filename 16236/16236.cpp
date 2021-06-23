/*실패*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
#define MP make_pair
typedef long long ll;

using namespace std;

int map[20][20];
struct Node
{
	int y;
	int x;
	int dist;
	Node(int _y, int _x, int _d)
	{
		y = _y, x = _x, dist = _d;
	}
};

struct Cmp{
	bool operator()(Node &a, Node &b)
	{
		if (a.dist > b.dist)
			return true;
		return false;
	}
};

int N;
Node BFS(int y, int x, int csize)
{
	int dy[4] = {-1, 0, 1, 0};
	int dx[4] = {0, 1 ,0, -1}; //상, 좌, 하, 우
	bool visit[20][20];
	memset(visit, 0, sizeof(visit));
	queue<Node> qu;
	priority_queue<pair<int, int> > candidate;
	int mindist = INF;
	qu.push(Node(y, x, 0));
	visit[y][x] = 1;
	while (!qu.empty())
	{
		Node here = qu.front();
		qu.pop();
		for (int i = 0; i < N; i++)
		{
			int ny = here.y + dy[i];
			int nx = here.x + dx[i];
			int nd = here.dist + 1;
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (map[ny][nx] > csize)
				continue;
			if (visit[ny][nx])
				continue;
			visit[ny][nx] = 1;
			if (map[ny][nx] >= 1 && map[ny][nx] < csize)
			{
				if (nd > mindist)
					break;
				mindist = nd;
				candidate.push(MP(-ny, -nx));
				continue;
			}
			qu.push(Node(ny, nx, nd));
		}
	}
	int ay = INF;
	int ax = INF, ad = mindist;
	if (!candidate.empty())
	{
		ay = -candidate.top().first;
		ax = -candidate.top().second;
	}
	return Node(ay, ax, ad);
}
int main() {
	FAST;
	int cy = 0, cx = 0, csize = 2;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				cy = i, cx = j;
				map[i][j] = 0;
			}
		}
	}
	int time = 0, eat = 0;
	while (true)
	{
		cout << "";
		Node dest = BFS(cy, cx, csize);
		if (dest.y >= INF)
			break;
		map[dest.y][dest.x] = 0;
		time += dest.dist;
		cy = dest.y, cx = dest.x;
		eat++;
		if (eat == csize)
		{
			eat = 0;
			csize++;
		}
	}
	cout << time << "\n";
}
