#include <cstdio>

using namespace std;
/*2의 개수보다 5의 개수가 더 적으므로 5의개수만 센다*/
int main()
{
	int N, five = 0;
	scanf("%d", &N);
	for (int i = 5; i <= N; i *= 5)
	{
		five += (N / i);
	}
	printf("%d", five);
}