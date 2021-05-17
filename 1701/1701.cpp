#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int	max_pi(string s, int n)
{
	int i, j = 0, maxpi = 0;
	vector<int> pi(n, 0);
	for (i = 1; i < n; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
		{
			pi[i] = ++j;
			maxpi = max(pi[i], maxpi);
		}
	}
	return (maxpi);
}

int main() {
	string str;
	cin >> str;
	int n = str.size();
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret = max(ret, max_pi(str.substr(i), n - i));
	}
	cout << ret;
}

