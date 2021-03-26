#include <cstdio>
#define PINF 987654321
#define NINF -987654321
using namespace std;

int ft_min(int a, int b)
{
	return (a < b) ? a : b;
}
int ft_max(int a, int b)
{
	return (a > b) ? a : b;
}
int main()
{
	int N,input, min = PINF, max = NINF;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &input);
		min = ft_min(input, min);
		max = ft_max(input, max);
	}
	printf("%d %d", min, max);
}