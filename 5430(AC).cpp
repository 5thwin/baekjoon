#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<int> arr;
void ft_r(int *start, int *end, int *rev)
{
	int tmp = *start;
	*start = *end;
	*end = tmp;
	*rev *= (-1);
}
void ft_d(int *start, int *end, int* rev)
{
	*start += *rev;
}
void ft_print(int start, int end, int rev, int sz)
{
	cout << "[";
	for (int i = 0; i < sz; i++)
	{
		cout << arr[start + i * rev];
		if (i != sz - 1)
			cout << ',';
	}
	cout << "]\n";
}
void store2arr(string str)
{
	int len = str.size();
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '[')
			num = 0;
		else if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		else if (str[i] == ',' || str[i] == ']')
		{
			if (num == 0)
				continue;
			arr.push_back(num);
			num = 0;
		}
	}
}
int main()
{
	int T, cmdlen, arrsz, start, end, N;
	int rev = 1;
	bool error = 0;
	string cmd;
	string str;
	cin >> T;
	while (T--)
	{
		arr.clear();
		error = 0;
		rev = 1;
		cin >> cmd >> N >> str;
		cmdlen = cmd.size();
		store2arr(str);
		arrsz = arr.size();
		start = 0, end = arrsz - 1;
		for (int i = 0; i < cmdlen; i++)
		{
			if (cmd[i] == 'R')
			{
				if (arrsz == 0)
					continue;
				ft_r(&start, &end, &rev);
			}
			if (cmd[i] == 'D')
			{
				if (arrsz == 0)
				{
					error = 1;
					break;
				}
				ft_d(&start, &end, &rev);
				arrsz--;
			}
		}
		if (error == 1)
			cout << "error\n";
		else
			ft_print(start, end, rev, arrsz);
	}
}