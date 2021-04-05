#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
using namespace std;
int N, M;
vector<string> map;
bool visit[1000][1000][2];
int ans = INF;
struct  Node
{
	int y;
	int x;
	int b;
	int length;
	Node(int _y, int _x, int _b, int _l) 
	{ y = _y; x = _x; b = _b; length = _l; }
};
void BFS(int y, int x)
{
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 }; //위, 아래, 왼쪽, 오른쪽
	queue<Node> qu;
	qu.push(Node(y, x, 0, 1));
	while (!qu.empty())
	{
		int cy = qu.front().y;
		int cx = qu.front().x;
		int cb = qu.front().b;
		int cl = qu.front().length;
		qu.pop();
		if (visit[cy][cx][cb])
			continue;
		visit[cy][cx][cb] = 1;
		if (cy == N - 1 && cx == M - 1)
			ans = min(ans, cl);
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			int nb = cb + (map[ny][nx] == '1' ? 1 : 0);
			if (nb >= 2)
				continue;
			if (visit[ny][nx][nb])
				continue;
			qu.push(Node(ny,nx,nb,cl + 1));
		}
	}
}
int main()
{
	FAST;
	cin >> N >> M;
	map.resize(N);
	for (int i = 0; i < N; i++)
		cin >> map[i];
	BFS(0, 0);
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;

}