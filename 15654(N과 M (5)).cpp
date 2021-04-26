#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, arr[8], prtarr[8];
void solve(int cur, int bit)
{
	if (cur == M) {
		for (int i = 0; i < M; i++)
		{
			cout << prtarr[i];
			if (i != N - 1)
				cout << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (bit & (1 << i))
			continue;
		prtarr[cur] = arr[i];
		solve(cur + 1, bit | 1 << i);
	}
}
int main()
{
	FAST;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	solve(0, 0);
}
