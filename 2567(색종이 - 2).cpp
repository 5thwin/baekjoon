#include <iostream>

using namespace std;

int map[100][100];
int cnt;
void fill_black(int a, int b)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[b + i][a + j] = 1;
		}
	}
}
bool ft_cnt(int a, int b)
{
	if (!map[b][a])
		return (0);
	int dy[8] = { 1,-1,0,0};
	int dx[8] = { 0,0,1,-1};
	for (int i = 0; i < 8; i++)
	{
		int ny = b + dy[i];
		int nx = a + dx[i];
		if (ny >= 100 || nx >= 100 || nx < 0 || ny < 0)
			cnt++;
		else if (!map[ny][nx])
			cnt++;
	}
	return (0);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, a, b;
	cin >> N;
	cnt = 0;
	while (N--)
	{
		cin >> a >> b;
		fill_black(a, b);
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			ft_cnt(j, i);
		}
	}
	cout << cnt;
}