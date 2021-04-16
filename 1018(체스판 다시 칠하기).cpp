#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
using namespace std;

int N, M;
char map[51][51];
int black_fraim(int y, int x)
{
	int cy, cx, change = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cy = y + i;
			cx = x + j;
			if ((i + j) % 2 == 0)
				change += (map[cy][cx] == 'B' ? 0 : 1);
			else
				change += (map[cy][cx] == 'W' ? 0 : 1);
		}
	}
	return change;
}
int white_frame(int y, int x)
{
	int cy, cx, change = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cy = y + i;
			cx = x + j;
			if ((i + j) % 2 == 0)
				change += (map[cy][cx] == 'W' ? 0 : 1);
			else
				change += (map[cy][cx] == 'B' ? 0 : 1);
		}
	}
	return change;
}
int main()
{
	FAST;
	cin >> N >> M;
	int repaint = INF;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	for (int y = 0; y <= N - 8; y++)
	{
		for (int x = 0; x <= M - 8; x++)
		{
			repaint = min(repaint, black_fraim(y, x));
			repaint = min(repaint, white_frame(y, x));
		}
	}
	cout << repaint;
}
