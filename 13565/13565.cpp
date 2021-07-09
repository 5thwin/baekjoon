#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int N, M;
vector< string > map;
int dy[4] = {0, 0, 1, -1}; //동, 서, 남, 북
int dx[4] = {1, -1 ,0 ,0};
bool visit[1000][1000];
bool dfs(int y, int x)
{
	if (y == N - 1)
		return (1); //전류가 안쪽까지 전달됨
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (map[ny][nx] == '1')
			continue; //인접해있는 칸이 부도체
		if (visit[ny][nx])
			continue;
		visit[ny][nx] = 1;
		if (dfs(ny, nx) == 1)
			return 1;
	}
	return (0);
}
int main() {
	FAST;
	cin >> N >> M;
	map.resize(N);
	string input;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	for (int sx = 0; sx < M; sx++)
	{
		if (map[0][sx] == '1')
			continue;
		if (dfs(0, sx))
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;

}

