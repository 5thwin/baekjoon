#include <iostream>

using namespace std;

void print_star(int i, int j, int num)
{
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1)
		printf(" ");
	else
	{
		if (num / 3 == 0)
			printf("*");
		else
			print_star(i, j, num / 3);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			print_star(i, j, n);
		}printf("\n");
	}
}