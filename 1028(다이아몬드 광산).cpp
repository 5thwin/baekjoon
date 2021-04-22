#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int R, C; //³ôÀÌ, ³ÐÀÌ
char map[751][751];
int Left[751][751];
int Right[751][751];
int main()
{
	FAST;
	int best_size = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> map[i];
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (map[y][x] == '0')
			{
				Left[y][x] = Right[y][x] = 0;
				continue;
			}
			best_size = max(best_size, 1);
			Left[y][x] = Right[y][x] =  1;
			if (x > 0 && y > 0)
				Left[y][x] = (map[y - 1][x - 1] == '0') ? 1 : Left[y - 1][x - 1] + 1;
			if (x < C - 1 && y > 0)
				Right[y][x] = (map[y - 1][x + 1] == '0') ? 1 : Right[y - 1][x + 1] + 1;
			int sz = min(Left[y][x], Right[y][x]);
			for (int i = sz - 1; i > 0; i--)
			{
				if (Right[y - i][x - i] >= (i + 1) && Left[y - i][x + i] >= (i + 1))
				{
					best_size = max(best_size, i + 1);
					break;
				}
			}
		}
	}
	cout << best_size << "\n";
}