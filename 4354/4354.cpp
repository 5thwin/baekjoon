//문자열 제곱
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

vector<int> getPi(string s)
{
	int n = s.size(), i, j = 0;
	vector<int> pi(n, 0);
	for (i = 1; i < n; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return (pi);
}

int main() {
	FAST;
	string s;
	vector<int> pi;
	while (1)
	{
		s.clear();
		cin >> s;
		if (s == ".")
			break;
		pi.clear();
		pi = getPi(s);
		int n = s.size();
		if (n % (n - pi[n - 1]) == 0)
			cout << n / (n - pi[n - 1]) << "\n";
		else
			cout << 1 << "\n";
	}
}

