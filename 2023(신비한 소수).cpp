#include <cstdio>
#include <cmath>
using namespace std;

int is_prime(int N)
{
	int root = sqrt(N);

	for (int i = 2; i <= root; i++)
	{
		if (N % i == 0)
			return (0);
	}
	return (1);
}
void solve(int num, int recur, int N)
{
	int prime;
	if (recur == N)
		printf("%d\n", num);
	for (int i = 0; i <= 9; i++)
	{
		if (recur == 0 && i < 2)
			continue;
		prime = num * 10 + i;
		if (is_prime(prime) == 1)
		{
			solve(prime, recur + 1, N);
		}
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	solve(0, 0, N);
}