#include <cstdio>

using namespace std;

int main()
{
	int input[8];

	for (int i = 0; i < 8; i++)
		scanf("%d", &input[i]);
	if (input[0] == 1)
	{
		for (int i = 1; i < 8; i++)
		{
			if (input[i] == input[i - 1] + 1)
				continue;
			printf("mixed\n");
			return (0);
		}
		printf("ascending\n");
		return (0);
	}
	if (input[0] == 8)
	{
		for (int i = 1; i < 8; i++)
		{
			if (input[i] == input[i - 1] - 1)
				continue;
			printf("mixed\n");
			return (0);
		}
		printf("descending\n");
		return (0);
	}
	printf("mixed\n");
	return (0);
}