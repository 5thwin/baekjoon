#include <cstdio>

using namespace std;

void swap(int i, int j, int* arr)
{
	arr[0] = arr[i];
	arr[i] = arr[j];
	arr[j] = arr[0];
}
void reverse(int i, int j, int *arr)
{
	int size = (j - i + 1);
	for (int t = 0; t < size / 2; t++)
		swap(i + t, j - t, arr);
}
int main()
{
	int basket[101], N, M, i, j;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		basket[i] = i;
	while (M--)
	{
		scanf("%d %d", &i, &j);
		reverse(i, j, basket);
	}
	for (int i = 1; i <= N; i++)
	{
		printf("%d", basket[i]);
		if (i != N)
			printf(" ");
	}
}