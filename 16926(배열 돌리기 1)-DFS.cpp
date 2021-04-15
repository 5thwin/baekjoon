#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF  987654321
#define MP make_pair
using namespace std;

int N, M, R;
vector<vector<int>> arr;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 }; //��, ��, ��, ��
int bound_y;
int bound_x;
int start_x;
int start_y;
void DFS(int y, int x, int change, int grp, int d) //���� y, ���� x,�ٲٴ� ��, �׷�, ����
{
	int tmp = arr[y][x];
	int ny = y + dy[d];
	int nx = x + dx[d]; //���� ��ġ
	if (d != 3 && (ny >= start_y + bound_y || nx >= start_x + bound_x || ny < start_y || nx < start_x)) //�� �̻� ��������� ������ ���⸸ Ʋ��
	{
		DFS(y, x, change, grp, d + 1);
	}
	else if (d == 3 && (ny >= start_y + bound_y || nx >= start_x + bound_x || ny < start_y || nx < start_x)) //������ �����̾��� ��������� ������ �ٲٰ� ������
	{
		arr[y][x] = change;
		return;
	}
	else //������ �� ������ �ٲٰ� ��� ����
	{
		arr[y][x] = change;
		DFS(ny, nx, tmp, grp, d);
	}
}
int main()
{
	FAST;
	cin >> N >> M >> R;
	int rotcnt;
	arr.resize(N, vector<int>(M));
	int grp = min(N, M) / 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < grp; i++)
	{
		bound_y = N - 2 * i;
		bound_x = M - 2 * i;
		rotcnt = R % ((2 * bound_y) + (2 * bound_x) - 4);
		start_y = start_x = i;
		while (rotcnt--)
			DFS(i, i, arr[i][i], i, 0);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}
