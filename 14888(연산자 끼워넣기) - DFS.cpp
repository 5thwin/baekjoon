#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 1000000001
#define NINF -1000000001
using namespace std;

int Arr[11] ,N;
int Mincal = INF, Maxcal = NINF;

void DFS(int num, int cur, int plus, int minus, int multi, int divid)
{
	if (cur == N - 1) // 모든 수를 계산
	{
		Mincal = min(Mincal, num);
		Maxcal = max(Maxcal, num);
		return ;
	}
	if (plus > 0)
		DFS(num + Arr[cur + 1], cur + 1, plus - 1, minus, multi, divid);
	if (minus > 0)
		DFS(num - Arr[cur + 1], cur + 1, plus, minus - 1, multi, divid);
	if (multi > 0)
		DFS(num * Arr[cur + 1], cur + 1, plus, minus, multi - 1, divid);
	if (divid > 0)
		DFS(num / Arr[cur + 1], cur + 1, plus, minus, multi, divid - 1);
}
int main()
{
	FAST;
	int plus, minus, multi, divid;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Arr[i];
	cin >> plus >> minus >> multi >> divid;
	DFS(Arr[0], 0, plus, minus, multi, divid);
	cout << Maxcal << "\n" << Mincal;
}
