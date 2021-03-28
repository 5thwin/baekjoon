#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	int N, mode, input, maxcnt = 0, sum = 0, maxnum = -4001, minnum = 4001;
	int check[8001];
	vector<pair<int, int>> arr;
	priority_queue<int> minqu;
	scanf("%d", &N);
	arr.resize(N);
	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		maxnum = max(maxnum, input);
		minnum = min(minnum, input);
		check[input + 4000]++;
		arr[i] = make_pair(input, check[input + 4000]);
		sum += input;
		maxcnt = max(maxcnt, check[input + 4000]);
	}
	sort(arr.begin(), arr.end());
	printf("%0.f\n%d\n", floor((double)sum / (double)N + 0.5), arr[N / 2]);
	for (int i = 0; i < N; i++)
	{
		if (arr[i].second == maxcnt)
			minqu.push(-arr[i].first);
	}
	if (minqu.size() >= 2)
		minqu.pop();
	printf("%d\n%d", -minqu.top(), maxnum - minnum);
	
}