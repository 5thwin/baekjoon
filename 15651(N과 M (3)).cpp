#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int N, M;
void recur(int rec, int* arr)
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
	for (int i = 1; i <= N; i++)
	{
		arr[rec] = i;
		recur(rec + 1, arr);
	}
}
int main()
{
	int arr[8];
	cin >> N >> M;
	recur(0, arr);
}