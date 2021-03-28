#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, x, y;
	vector<pair<int, int>> arr;
	scanf("%d", &N);
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		arr[i] = make_pair(x, y);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", arr[i].first, arr[i].second);
	}
}