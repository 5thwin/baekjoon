#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isgrp(string s)
{
	int ln = s.size();
	bool alpha[26];
	char now = s[0];

	memset(alpha, 0, sizeof(alpha));
	alpha[now - 'a'] = 1;
	for (int i = 1; i < ln; i++)
	{
		now = s[i];
		if (now == s[i - 1])
			continue;
		if (alpha[now - 'a'] == 0)
			alpha[now - 'a'] = 1;
		else
			return (0);
	}
	return (1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, grp_word = 0;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		grp_word += isgrp(str) ? 1 : 0;
	}
	cout << grp_word;
}
