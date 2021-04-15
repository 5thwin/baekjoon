#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF  987654321
#define MP make_pair
using namespace std;

vector<vector<int>> arr;
int N, M, R; //높이, 넓이, 연산수

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void ft_1()
{
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < M; j++)
			swap(&arr[i][j], &arr[N - 1 - i][j]);
	}
}
void ft_2()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M / 2; j++)
			swap(&arr[i][j], &arr[i][M - 1 - j]);
	}
}

void ft_3()
{
	vector<vector<int>> tmp(M, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmp[j][N - 1 - i] = arr[i][j];
		}
	}
	arr.clear();
	arr = tmp;
	swap(&N, &M);
}
void ft_4()
{
	vector<vector<int>> tmp(M, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmp[M - 1 - j][i] = arr[i][j];
		}
	}
	arr.clear();
	arr = tmp;
	swap(&N, &M);
}
void ft_5()
{
	int tmp;
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < M / 2; j++)
		{
			tmp = arr[i][j];
			swap(&tmp, &arr[i][j + M / 2]);
			swap(&tmp, &arr[i + N/2][j + M/2]);
			swap(&tmp, &arr[i + N/2][j]);
			swap(&tmp, &arr[i][j]);
		}
	}
}
void ft_6()
{
	int tmp;
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < M / 2; j++)
		{
			tmp = arr[i][j];
			swap(&tmp, &arr[i + N/2][j]);
			swap(&tmp, &arr[i + N/2][j + M/2]);
			swap(&tmp, &arr[i][j + M/2]);
			swap(&tmp, &arr[i][j]);
		}
	}
}
int main()
{
	FAST;
	cin >> N >> M >> R;
	int oper;
	arr.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < R; i++)
	{
		cin >> oper;
		if (oper == 1)
			ft_1();
		if (oper == 2)
			ft_2();
		if (oper == 3)
			ft_3();
		if (oper == 4)
			ft_4();
		if (oper == 5)
			ft_5();
		if (oper == 6)
			ft_6();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}