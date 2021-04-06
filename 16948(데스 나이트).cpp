#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
using namespace std;

int N;
int c1, r1, c2, r2, ans;
bool visit[200][200];

struct Node
{
	int y;
	int x;
	int dist;
	Node(int _y, int _x, int _d) { y = _y; x = _x; dist = _d; }
};

int Bfs(int y, int x)
{
	int dy[6] = {-1, 1, -2, 2, -1, 1};
	int dx[6] = {-2, -2, 0, 0, 2, 2};//(r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)
	queue<Node> qu;
	qu.push(Node(y, x, 0));
	while (!qu.empty())
	{
		int cy = qu.front().y;
		int cx = qu.front().x;
		int cd = qu.front().dist;
		qu.pop();
		if (visit[cy][cx])
			continue;
		visit[cy][cx] = 1;
		if (c2 == cy && r2 == cx)
			return cd;
		for (int i = 0; i < 6; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nd = cd + 1;
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visit[ny][nx])
				continue;
			qu.push(Node(ny, nx, nd));
		}
	}
	return (0);
}
int main()
{
	FAST;

	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;
	ans = Bfs(c1, r1);
	if (!visit[c2][r2])
		cout << "-1";
	else
		cout << ans;
}