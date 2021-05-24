//16916 부분문자열
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

vector<int> getPi(string s)
{
	int n = s.size();
	int i, j = 0;
	vector<int> pi(n, 0);
	for (i = 1; i < n; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}

int kmp(string s, string p, vector<int> pi)
{
	int n = s.size();
	int m = p.size();
	int i, j = 0;

	for (int i = 0; i < n; i++)
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
	FAST;
	string s, p;
	cin >> s >> p;
	vector<int> pi = getPi(p);
	cout << kmp(s, p, pi) << "\n";
}

