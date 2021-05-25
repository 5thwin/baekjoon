/*나는 친구가 적다 (Large)*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

vector<int> getPi(string p, int m)
{
	vector<int> pi(m, 0);
	int i, j = 0;

	for (i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

int kmp(string s, string p, vector<int> pi, int n, int m)
{
	int i, j = 0;
	for (i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j])
		{
			if (j == m - 1)
				return (1);
			else
				j++;
		}
	}
	return (0);
}

int main() {
	string origin, s, p;
	cin >> origin;
	cin >> p;
	int origin_len = origin.size();
	for (int i = 0; i < origin_len; i++)
	{
		if (!isdigit(origin[i]))
			s.push_back(origin[i]);
	}
	int n = s.size(), m = p.size();
	vector<int> pi = getPi(p, m);
	cout << kmp(s, p, pi, n, m);
}

