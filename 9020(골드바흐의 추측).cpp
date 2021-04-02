#include<stdio.h>
#include <cstring>
using namespace std;

int main()
{
	int T, n, b, ansa, ansb;
	bool prime[10001];
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;

	for (int i = 2; i <= 10000; i++)
	{
		if (!prime[i])
			continue;
		for (int j = i + i; j <= 10000; j += i)
			prime[j] = 0;
	}

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int a = 2; a <= n / 2; a++)
		{
			if (!prime[a])
				continue;
			b = n - a;
			if (!prime[b])
				continue;
			ansa = a;
			ansb = b;
		}
		printf("%d %d\n", ansa, ansb);
	}
}
