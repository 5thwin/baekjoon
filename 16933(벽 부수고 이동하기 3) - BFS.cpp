#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
using namespace std;
int N, M, K;
vector<string> map;
bool visit[1000][1000][11][2];
int ans = INF;
struct  Node
{
	int y;
	int x;
	int b;
	int length;
	int day; // 0 = 낮, 1 = 밤
	Node(int _y, int _x, int _b, int _l, int _d)
	{
		y = _y; x = _x; b = _b; length = _l; day = _d;
	}
};
void BFS(int y, int x)
{
	int dy[5] = { -1, 1, 0, 0, 0 };
	int dx[5] = { 0, 0, -1, 1, 0 }; //위, 아래, 왼쪽, 오른쪽, 이동안함
	queue<Node> qu;
	qu.push(Node(y, x, 0, 1, 0));
	while (!qu.empty())
	{
		int cy = qu.front().y;
		int cx = qu.front().x;
		int cb = qu.front().b;
		int cl = qu.front().length;
		int cd = qu.front().day;
		qu.pop();
		if (visit[cy][cx][cb][cd])
			continue;
		visit[cy][cx][cb][cd] = 1;
		if (cy == N - 1 && cx == M - 1)
			ans = min(ans, cl);
		for (int i = 0; i < 5; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (map[ny][nx] == '1' && cd == 1 && i != 4) /*i != 4 조건이 필요한 이유 -> 움직이지 않았으면서, map[ny][nx]에 벽이 있는 경우는 이미 부순 벽이다.*/
				continue;
			int nb = cb + ((map[ny][nx] == '1' && cd == 0) ? 1 : 0);
			if (nb > K)
				continue;
			if (visit[ny][nx][nb][cd == 0 ? 1 : 0])
				continue;
			qu.push(Node(ny, nx, nb, cl + 1, cd == 0 ? 1 : 0));
		}
	}
}
int main()
{
	FAST;
	cin >> N >> M >> K;
	map.resize(N);
	for (int i = 0; i < N; i++)
		cin >> map[i];
	BFS(0, 0);
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;

}