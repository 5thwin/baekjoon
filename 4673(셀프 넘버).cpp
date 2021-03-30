#include <cstdio>
#include <cstring>
using namespace std;

bool hasgen[10001];
int ft_d(int n)
{
	int ret = n;
	while (n)
	{
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int D;
	memset(hasgen, 0, sizeof(hasgen));
	for (int i = 1; (D = ft_d(i)) <= 11106; i++) //11106Àº D[9999]
	{
		hasgen[D] = 1;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (!hasgen[i])
			printf("%d\n", i);
	}
}