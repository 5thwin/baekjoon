#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int arr[10001], input, N;
	memset(arr, 0, sizeof(arr));
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &input);
		arr[input]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}
}