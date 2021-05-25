#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

vector<int> getPi(string p, int n)
{
	int i, j = 0;
	vector<int> pi(n, 0);

	for (i = 1; i < n; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

int	kmp(string s, string p, vector<int> pi, int N)
{
	int i, j = 0, cnt = 0;
	int n = 2 * N, m = N;

	for (i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j])
			j = pi[j-1];
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				cnt++;
				j = pi[j];
			}
			else
				j++;
		}
	}
	return cnt;
}

int GCD(int a, int b)
{
	if (b == 0)
		return (a);
	return GCD(b, a % b);
}

int main() {
	FAST;
	string s, p;
	int N;
	unsigned char input;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		p.push_back(input);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		s.push_back(input);
	}
	s = s + s.substr(0, N - 1);
	vector<int> pi = getPi(p, N);
	int son = kmp(s, p, pi, N);
	int gcd = GCD(son, N);
	if (son < N)
		cout << son / gcd << "/" << N / gcd << "\n";
	else
		cout << "1/1";
}

