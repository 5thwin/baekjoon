#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);

typedef long long ll;
using namespace std;

int dr[4] = {-1, 1, 0, 0}; //위 아래 오른쪽 왼쪽
int dc[4] = {0, 0, -1, 1};
struct Shark
{
	int r, c, s, d, z;
	bool alive;
	//(r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기
	Shark(int _r, int _c, int _s, int _d, int _z)
	{
		r = _r, c = _c, s = _s, d = _d, z = _z;
		alive = 1;
	}
};

vector<Shark> shark;

void shark_move(Shark *sk, int R, int C)
{
	int r = sk->r, c = sk->c;
	int s = sk->s, d = sk->d;
	while (s > 0)
	{
		if (d == 0) //위로 움직이는 상어
		{
			if (r - s < 0)
			{
				s -= r;
				r = 0;
				d = 1;
			}
			else
			{
				r -= s;
				s = 0;
			}
		}
		else if (d == 1) //아래로 움직이는 상어
		{
			if (r + s >= R)
			{
				s -= (R - 1 - r);
				r = R - 1;
				d = 0;
			}
			else
			{
				r += s;
				s = 0;
			}
		}
		else if (d == 2) // 오른쪽으로 움직이는 상어
		{
			if (c + s >= C)
			{
				s -= (C - 1 - c);
				c = C - 1;
				d = 3;
			}
			else
			{
				c += s;
				s = 0;
			}
		}
		else //왼쪽으로 움직이는 상어
		{
			if (c - s < 0)
			{
				s -= c;
				c = 0;
				d = 2;
			}
			else
			{
				c -= s;
				s = 0;
			}
		}
	}
	sk->r = r, sk->c = c, sk->d = d;
}
int map[101][101];
int main()
{
	FAST;
	int R, C, N, r, c, s, d, z; //R 세로길이 C 가로길이
	cin >> R >> C >> N;
	memset(map, -1, sizeof(map));
	for (int i = 0; i < N; i++)
	{
		cin >> r >> c >> s >> d >> z;
		shark.push_back(Shark(r - 1, c - 1, s, d - 1, z));
		map[r - 1][c - 1] = i; //map에 상어번호를 표시
	}

	int total = 0;
	for (int p = 0; p < C; p++)
	{
		//1. 낚시꾼이 상어를 잡음
		for (int i = 0; i < R; i++)
		{
			int here = map[i][p];
			if (here == -1)
				continue;
			if (!shark[here].alive)
				continue;
			shark[here].alive = 0;
			total += shark[here].z;
			map[shark[here].r][shark[here].c] = -1;
			break;
		}
		//2. 상어의 이동
		for (int i = 0; i < N; i++)
		{
			if (!shark[i].alive) //이미 죽은 상어
				continue;
			if (map[shark[i].r][shark[i].c] == i) //이 자리에 새로 온 상어가 없으므로이동할때 비워줌
				map[shark[i].r][shark[i].c] = -1;
			shark_move(&shark[i], R, C);
			if (map[shark[i].r][shark[i].c] == -1 || map[shark[i].r][shark[i].c] > i) //이동한 자리에 상어가 없거나 아직 이동하지 않은 상어
				map[shark[i].r][shark[i].c] = i;
			else //이미 이동한 상어가 있으므로 크기싸움
			{
				int oth = map[shark[i].r][shark[i].c];
				int win = (shark[i].z > shark[oth].z) ? i : oth;
				int lose = (shark[i].z > shark[oth].z) ? oth : i;
				shark[lose].alive = 0;
				map[shark[i].r][shark[i].c] = win;
			}
		}
	}
	cout << total << "\n";
}
