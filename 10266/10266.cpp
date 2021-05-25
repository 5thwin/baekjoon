/*시계사진들*/
#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

vector<int> getPi(vector<int> p, int n)
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

int kmp(vector<int> s, vector<int> p, vector<int> pi, int n)
{
	int i, j = 0;
	int m = n;
	n = 2 * n - 1;
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
	FAST;
	int N, input;
	cin >> N;
	vector<int> clock1, clock2, s, p;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		clock1.push_back(input);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		clock2.push_back(input);
	}
	sort(clock1.begin(), clock1.end());
	sort(clock2.begin(), clock2.end());
	for (int i = 1; i < N; i++)
	{
		s.push_back(clock1[i] - clock1[i - 1]);
		p.push_back(clock2[i] - clock2[i - 1]);
	}
	s.push_back(clock1[0] - clock1[N - 1] + 360000);
	for (int i = 0; i < N - 1; i++)
		s.push_back(s[i]);
	p.push_back(clock2[0] - clock2[N - 1] + 360000);
	vector<int> pi = getPi(p, N);
	if (kmp(s, p, pi, N) == 1)
		cout << "possible\n";
	else
		cout << "impossible\n";

}

