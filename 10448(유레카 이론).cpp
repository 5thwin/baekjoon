#include <cstdio>
#include <cstring>
using namespace std;

char dp[1001][3];
int ft_T(int num)
{
	return (((num + 1) * num) / 2);
}

char solve(int N, int cnt)
{
	char& ref = dp[N][cnt];
	int tmp;
	if (ref != -1)
		return ref;
	if (cnt == 0 || N == 0)
		return ref = 0;
	for (int i = 1; (tmp = ft_T(i)) <= N; i++)
	{
		if (solve(N - tmp, cnt - 1))
			return ref = 1;
	}
	return ref = 0;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	
	int T, N, tmp, i = 1;
	while ((tmp = ft_T(i)) <= 1000)
	{
		dp[tmp][0] = 1;
		i++;
	}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		printf("%d\n", solve(N, 2));
	}
}