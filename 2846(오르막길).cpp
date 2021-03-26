#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, ans = 0, h = 0, pre = 1001, now;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &now);
		if (pre < now)
		{
			h += now - pre;
			ans = max(ans, h);
		}
		else
			h = 0;
		pre = now;
	}
	printf("%d", ans);
}