#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int input, idx = 0, ansmax = -1;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &input);
		if (input > ansmax)
		{
			ansmax = input;
			idx = i + 1;
		}
	}
	printf("%d\n%d", ansmax, idx);
}