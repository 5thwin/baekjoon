#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int N, M;
int bit_on(int n, int k)
{
	return (n | (1 << k));
}
int visit_check(int bit, int k)
{
	return (bit & bit_on(1, k));
}
void recur(int rec, int bit, int* arr)
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
		if (visit_check(bit, i))
			continue;
		arr[rec] = i;
		bit = bit_on(bit, i);
		recur(rec + 1, bit, arr);
	}
}
int main()
{
	int arr[8];
	cin >> N >> M;
	recur(0, 0, arr);
}