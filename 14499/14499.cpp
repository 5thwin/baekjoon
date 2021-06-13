/*주사위 굴리기*/
#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int N, M, K;
int map[20][20];

struct Dice
{
	/* data */
	int b, t, e, w, s, n;
	Dice(){b = t = e = w = s = n = 0;}
	void init(int _b, int _t, int _e, int _w, int _s, int _n)
	{
		b = _b, t = _t, e = _e, w = _w, s = _s, n = _n;
	}
	void roll_n() //북쪽으로 굴림
	{
		init(n, s, e, w, b, t);
	}
	void roll_s() //남쪽으로 굴림
	{
		init(s, n, e, w, t, b);
	}
	void roll_e()
	{
		init(e, w, t, b, s, n);
	}
	void roll_w()
	{
		init(w, e, b, t, s, n);
	}
};

void	update(Dice *dice, int y, int x)
{
	if (map[y][x] == 0)
	{
		map[y][x] = dice->b;
	}
	else
	{
		dice->b = map[y][x];
		map[y][x] = 0;
	}
}

int main() {
	int x, y, cmd;
	Dice dice;
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	while (K--)
	{
		cin >> cmd; // 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
		if (cmd == 1)
		{
			if (x + 1 >= M)
				continue;
			x++;
			dice.roll_e();
		}
		else if (cmd == 2)
		{
			if (x - 1 < 0)
				continue;
			x--;
			dice.roll_w();
		}
		else if (cmd == 3)
		{
			if (y - 1 < 0)
				continue;
			y--;
			dice.roll_n();
		}
		else
		{
			if (y + 1 >= N)
				continue;
			y++;
			dice.roll_s();
		}
		update(&dice, y, x);
		cout << dice.t << "\n";
	}
}

