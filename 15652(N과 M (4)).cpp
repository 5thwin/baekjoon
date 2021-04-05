#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
int N, M;
int arr[8];
void dfs(int rec)
{
	if (rec == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i];
			if (i != M - 1)
				cout << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = (rec == 0) ? 1 : arr[rec - 1]; i <= N; i++)
	{

		arr[rec] = i;
		dfs(rec + 1);
	}
}
int main()
{
	FAST;
	cin >> N >> M;
	dfs(0);
}