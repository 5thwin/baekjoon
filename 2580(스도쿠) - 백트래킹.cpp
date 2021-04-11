#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
using namespace std;

int map[9][9], zero = 0;
vector<pair<int, int>> blank;

void in_block(int y, int x, bool* candidate)
{
	int block_y = (y / 3) * 3;
	int block_x = (x / 3) * 3;

	for (int cy = block_y; cy < block_y + 3; cy++)
	{
		for (int cx = block_x; cx < block_x + 3; cx++)
		{
			if (y == cy && x == cx)
				continue;
			if (map[cy][cx] == 0)
				continue;
			if (candidate[map[cy][cx]] != 0)
				candidate[map[cy][cx]] = 0;
		}
	}
}

void in_row(int y, int x, bool* candidate)
{
	int row = y;

	for (int i = 0; i < 9; i++)
	{
		if (x == i)
			continue;
		if (map[row][i] == 0)
			continue;
		if (candidate[map[row][i]] != 0)
			candidate[map[row][i]] = 0;
	}
}

void in_col(int y, int x, bool* candidate)
{
	int col = x;
	for (int i = 0; i < 9; i++)
	{
		if (y == i)
			continue;
		if (map[i][col] == 0)
			continue;
		if (candidate[map[i][col]] != 0)
			candidate[map[i][col]] = 0;
	}
}

bool solve(int num)
{
	if (num == zero)
		return (1);
	int y = blank[num].first;
	int x = blank[num].second;
	bool candidate[10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	in_block(y, x, candidate);
	in_row(y, x, candidate);
	in_col(y, x, candidate);
	for (int i = 1; i <= 9; i++)
	{
		if (candidate[i] == 0)
			continue;
		map[y][x] = i;
		if (solve(num + 1))
			return (1);
	}
	map[y][x] = 0;
	return (0);
}
int main()
{
	FAST;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				blank.push_back(MP(i, j));
		}
	}
	zero = blank.size();
	solve(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << map[i][j] << " ";
		}cout << "\n";
	}
}

/*
0 6 0 0 0 0 2 0 9
0 0 0 8 2 0 5 0 0
0 1 0 9 0 3 0 0 0
3 7 0 0 9 0 0 0 6
1 0 0 0 0 0 0 0 8
2 0 0 0 4 0 0 5 1
0 0 0 5 0 4 0 9 0
0 0 3 0 7 9 0 0 0
5 0 9 0 0 0 0 6 0

6 0 0 4 1 0 0 0 0
0 2 0 0 6 3 0 0 1
0 0 9 8 0 0 0 0 4
9 0 8 0 7 6 1 0 2
2 6 0 0 0 0 0 9 3
4 0 1 2 9 0 7 0 6
1 0 0 0 0 5 3 0 0
5 0 0 6 3 0 0 7 0
0 0 0 0 4 2 0 0 5

0 0 0 7 5 0 0 3 0
1 0 6 0 0 0 0 0 0
8 0 0 3 0 0 0 0 0
0 2 0 0 0 0 0 4 0
0 0 0 6 0 0 8 0 0
0 0 0 0 0 1 0 0 0
0 4 0 0 9 0 0 0 0
3 0 0 0 4 0 0 0 0
0 0 0 0 0 0 1 0 0
*/