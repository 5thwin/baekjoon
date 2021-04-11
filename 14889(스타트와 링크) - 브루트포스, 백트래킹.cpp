#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
#define ABS(X) (X) < 0 ? -(X) : (X)
using namespace std;

int N;
int S[20][20];
int mem1[10];
int mem2[10];
int ans = INF;
//void print_mem()
//{
//	cout << "mem 1 :";
//	for (int i = 0; i < N / 2; i++)
//		cout << mem1[i] << " ";
//	cout << "mem 2 :";
//	for (int i = 0; i < N / 2; i++)
//		cout << mem2[i] << " ";
//	cout << "\n";
//}
int dif(int n)
{
	int ab1 = 0, ab2 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; j++)
		{
			ab1 += S[mem1[i]][mem1[j]];
			ab1 += S[mem1[j]][mem1[i]];
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; j++)
		{
			ab2 += S[mem2[i]][mem2[j]];
			ab2 += S[mem2[j]][mem2[i]];
		}
	}
	return ABS(ab1 - ab2);
}
void start_team(int cur, int n) // n = N / 2
{
	if (cur == n)
	{
		int i = 0, j = 0;
		for (int k = 0; k < N; k++)
		{
			if (mem1[i] == k)
				i++;
			else
				mem2[j++] = k;
		}
		ans = (min(ans, dif(n)));
		return;
	}
	for (int i = (cur == 0) ? 0 : mem1[cur - 1] + 1; i < N - (n - 1 -cur); i++)
	{
		mem1[cur] = i;
		start_team(cur + 1, n);
	}
}
int main()
{
	FAST;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> S[i][j];
		}
	}
	start_team(0, N / 2);
	cout << ans;
}