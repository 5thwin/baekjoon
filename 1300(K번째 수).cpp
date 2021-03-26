/*K¹øÂ° ¼ö*/
#include <cstdio>
#include <algorithm>
using namespace std;

int small_cnt(int num, int N)
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
		cnt += min(N, num / i);
	return cnt;
}
int main()
{
	int N, K, scnt, beg, end, mid, result;
	scanf("%d %d", &N, &K);
	beg = 1;
	end = K;
	mid = 1;
	while (beg <= end)
	{
		mid = (beg + end) / 2;
		scnt = small_cnt(mid, N);
		if (scnt < K)
			beg = mid + 1;
		else if (scnt >= K)
		{
			result = mid;
			end = mid - 1;
		}
	}
	printf("%d", result);
}