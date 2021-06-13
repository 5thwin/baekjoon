/*로봇 청소기*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define RT(X) ((X) + 3) % 4
#define OUT_RANGE(y,x) (y < 0 || y >= N || x < 0 || x >= M)
using namespace std;

int map[50][50];
int visit[50][50];
int dy[4] = {-1, 0, 1, 0}; //북 동 남 서
int dx[4] = {0, 1, 0, -1};
int N, M;
int simulate(int cy, int cx, int cd, int rotate)
{
	int clean, nd, nx, ny;
	if (rotate == 4) //네 방향 모두 탐색
	{
		nd = RT(RT(cd)); //뒤 방향
		ny = cy + dy[nd], nx = cx + dx[nd];
		if (OUT_RANGE(ny, nx)) //d 뒤로 가면 범위 밖 - 작동 중지
			return 0;
		if (map[ny][nx] == 1) //d 뒤에 벽 - 작동 중지
			return 0;
		return simulate(ny, nx, cd, 0); //c 보는 방향 그대로 뒤로 한간 이동
	}
	clean = 0; //현재 자리 청소여부
	if (visit[cy][cx] == 0)
		visit[cy][cx] = clean = 1;
	nd = RT(cd);
	ny = cy + dy[nd], nx = cx + dx[nd];

	if (OUT_RANGE(ny, nx)) // b 왼쪽이 범위 바깥이라 청소할 수 없음
		return clean + simulate(cy, cx, nd, rotate + 1);
	else
	{
		if (!map[ny][nx] && !visit[ny][nx]) //a .왼쪽에 청소하지 않은 공간이 있음
			return clean + simulate(ny, nx, nd, 0);
		else	// b. 왼쪽에 벽이 위치하거나 청소를 이미했음
			return clean + simulate(cy, cx, nd, rotate + 1);
	}
}

int main() {
	FAST;
	int cy, cx, cd;
	cin >> N >> M;
	cin >> cy >> cx >> cd;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
			cin >> map[r][c];
	}
	memset(visit, 0 ,sizeof(visit));
	cout << simulate(cy,cx,cd,0);
}
