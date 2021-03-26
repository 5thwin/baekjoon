#include <cstdio>

using namespace std;

void swap(int* arr, int i, int j)
{
	arr[0] = arr[i];
	arr[i] = arr[j];
	arr[j] = arr[0];
}
int main()
{
	int N, M, i,j, basket[101];
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		basket[i] = i;
	while (M--)
	{
		scanf("%d %d", &i, &j);
		swap(basket, i, j);
	}
	for (int i = 1; i <= N; i++)
	{
		printf("%d", basket[i]);
		if (i != N)
			printf(" ");
	}
}