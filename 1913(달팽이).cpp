#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int N, tN, num, y, x, find, ansy, ansx;
	vector<vector<int>> table;
	scanf("%d %d", &N, &find);
	tN = N;
	table.resize(N, vector<int>(N));
	num = N * N;
	y = x = 0;
	ansy = N / 2;
	ansx = N / 2;
	while (N > 1)
	{
		
		for (int i = 0; i < N; i++)
		{
			if (find == num)
			{
				ansy = y;
				ansx = x;
			}
			table[y++][x] = num--;
		}
		y--;
		x++;
		for (int i = 0; i < N - 1; i++)
		{
			if (find == num)
			{
				ansy = y;
				ansx = x;
			}
			table[y][x++] = num--;
		}
		x--;
		y--;
		for (int i = 0; i < N - 1; i++)
		{
			if (find == num)
			{
				ansy = y;
				ansx = x;
			}
			table[y--][x] = num--;
		}
		y++;
		x--;
		for (int i = 0; i < N - 2; i++)
		{
			if (find == num)
			{
				ansy = y;
				ansx = x;
			}
			table[y][x--] = num--;
		}
		y++;
		x++;
		N -= 2;
	}
	table[tN / 2][tN / 2] = 1;
	for (int i = 0; i < tN; i++)
	{
		for (int j = 0; j < tN; j++)
		{
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", ansy + 1, ansx + 1);
}