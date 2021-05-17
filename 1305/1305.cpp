#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

vector<int> getPi(string s, int n)
{
	int i, j = 0;
	vector<int> pi(n, 0);
	for (i = 1; i < n; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}

int main() {
	FAST;
	int N;
	string s;
	cin >> N;
	cin >> s;
	vector<int> pi = getPi(s, N);
	cout << N - pi[N-1];
}

