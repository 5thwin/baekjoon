/*뱀*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; //우,하,좌,상
int N, K, L, map[100][100]; // 1사과, -1뱀 몸
queue<pair<int, char> > qu;

struct Snake
{
	int hy;
	int hx;
	queue<pair<int, int> > body;
	int time;
	int dir;
	Snake()
	{
		hy = hx = 0;
		time = dir = 0;
	}
};

int play(Snake sn)
{
	int tx, ty;
	if (qu.empty())
		;
	else if (sn.time == qu.front().first) //방향을 트는 경우
	{
		if (qu.front().second == 'L') //왼쪽으로 90도
			sn.dir = (sn.dir + 3) % 4;
		else	//오른쪽으로 90도
			sn.dir = (sn.dir + 1) % 4;
		qu.pop();
	}
	sn.time++;
	sn.hy += dy[sn.dir];
	sn.hx += dx[sn.dir];
	if (sn.hy < 0 || sn.hy >= N || sn.hx < 0 || sn.hx >= N)
		return sn.time;
	if (map[sn.hy][sn.hx] == -1)
		return sn.time;
	sn.body.push(MP(sn.hy, sn.hx));
	if (map[sn.hy][sn.hx] == 0) //사과를 먹지 않음
	{
		ty = sn.body.front().first;
		tx = sn.body.front().second;
		sn.body.pop();
		map[ty][tx] = 0;
	}
	map[sn.hy][sn.hx] = -1;
	return (play(sn));
}
int main() {
	FAST;
	cin >> N >> K;
	int x, y;
	char z;
	while (K--)
	{
		cin >> y >> x;
		map[y - 1][x - 1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> x >> z;
		qu.push(MP(x, z));
	}
	map[0][0] = -1;
	Snake sn;
	cout << play(sn);
}

