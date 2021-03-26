#include <iostream>
#include <cstring>

int main()
{
	bool check[1001];
	int ans = 0, input;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &input);
		if (check[input % 42])
			continue;
		check[input % 42] = 1;
		ans++;
	}
	printf("%d", ans);
	return (0);
}