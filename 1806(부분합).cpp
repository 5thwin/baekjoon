#include<stdio.h>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int N, S;
	int arr[100000];
	int sum = 0, sl, s = 0, e = 0;
	scanf("%d %d", &N, &S);
	sl = N + 1;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	while(e < N)
	{
		sum += arr[e];
		while (sum > S && s <= e)
		{
			if (sum - arr[s] >= S)
			{
				sum -= arr[s];
				s++;
			}
			else
				break;
		}
		if (sum >= S)
			sl = min(sl, e - s + 1);
		e++;
	}
	if (sl > N)
		printf("0");
	else
		printf("%d", sl);
}
/*
10 15
5 1 3 5 10 7 4 9 2 8
*/