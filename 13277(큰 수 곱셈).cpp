#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int ctoi(char c)
{
	return c - '0';
}

int cmult(char c1, char c2)
{
	return ctoi(c1) * ctoi(c2);
}

void add_up(char *cache, int up, int idx)
{
	cache[idx] += up;
	while (cache[idx] >= 10)
	{
		cache[idx] %= 10;
		cache[idx + 1]++;
		idx++;
	}
}

void	print_format(char *cache, int start)
{
	int idx = start;
	bool nonzero = 1;
	while (idx >= 0)
	{
		if (cache[idx] == 0 && nonzero == 1)
		{
			idx--;
			continue;
		}
		nonzero = 0;
		cout << (int)cache[idx];
		idx--;
	}

}
int		main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;
	int pos1, pos2, up = 0, mult, idx, start = 0;
	int len1, len2;
	char cache[300001];

	cin >> str1;
	cin >> str2;
	memset(cache, 0, sizeof(cache));
	len1 = str1.size();
	len2 = str2.size();
	
	if (str1[0] == '0' || str2[0] == '0')
	{
		cout << "0";
		return 0;
	}

	pos2 = len2 - 1;
	while (pos2 >= 0)
	{
		idx = start;
		pos1 =len1 - 1;
		while (pos1 >= 0)
		{
			mult = cmult(str1[pos1], str2[pos2]);
			up = mult / 10;
			cache[idx] += mult % 10;
			if (cache[idx] >= 10)
			{
				cache[idx] %= 10;
				up++;
			}
			add_up(cache, up, idx + 1);
			pos1--;
			idx++;
		}
		start++;
		pos2--;
	}
	print_format(cache, len1 + len2 - 1);
	return 0;
}