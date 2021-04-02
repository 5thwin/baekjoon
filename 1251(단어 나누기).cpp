#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void printrev(string s, int start, int last)
{
	while (last >= start)
		cout << s[last--];
}
int ft_first(string s, int a, int b)
{
	int idx1 = a, idx2 = b;
	while (idx1 > 0 && idx2 > 0)
	{
		if (s[idx1] != s[idx2])
			break;
		idx1--;
		idx2--;
	}
	if (s[idx1] <= s[idx2])
		return (a);
	else
		return (b);
}
void recur(string s, int start, int end, int rec)
{
	if (rec == 2)
	{
		printrev(s, start, end - 1);
		return;
	}
	char minchar = 'z' + 1;
	int minidx = end - 1;
	int i;
	for (i = start; i < end - (2 - rec); i++)
	{
		if (s[i] < minchar)
		{
			minidx = i;
			minchar = s[i];
		}
		else if (s[i] == minchar)
		{
			minidx = ft_first(s, minidx, i);
			minchar = s[minidx];
		}
	}
	printrev(s, start, minidx);
	recur(s, minidx + 1, end, rec + 1);
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	int len;
	cin >> str;
	len = str.size();
	recur(str, 0, len, 0);
}
/*cabadd*/