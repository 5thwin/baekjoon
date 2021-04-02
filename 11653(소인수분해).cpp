#include <iostream>

using namespace std;

int main()
{
	int N, div = 2;
	scanf("%d", &N);
	while (N > 1)
	{
		if (N % div == 0)
		{
			printf("%d\n", div);
			N /= div;
			continue;
		}
		div++;
	}
}