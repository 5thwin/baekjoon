#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int N, K, len[100];

vector<int> getpi(vector<int> code, int start)
{
	vector<int> pi(K, 0);
	int i, j = 0;
	for (i = 1; i < K; i++)
	{
		while (j > 0 && code[i + start] != code[j + start])
			j = pi[j - 1];
		if (code[i + start] == code[j + start])
			pi[i] = ++j;
	}
	return pi;
}

int kmp(vector<int> S, vector<int> P, int t, vector<int> pi)
{
	int i, j = 0;
	int ls = S.size();
	for (int i = 0; i < ls; i++)
	{
		while (j > 0 && S[i] != P[j + t])
			j = pi[j - 1];
		if (S[i] == P[j + t])
		{
			if (j == K - 1)
				return (1);
			else
				j++;
		}
	}
	return (0);
}

int main() {
	FAST; int tmp;
	cin >> N >> K;
	vector< vector<int> > code(N);
	vector< vector<int> > rcode(N);
	for (int i = 0; i < N; i++)
	{
		cin >> len[i];
		code[i].resize(len[i]);
		rcode[i].resize(len[i]);
		for (int j = 0; j < len[i]; j++)
		{
			cin >> tmp;
			code[i][j] = rcode[i][len[i] - j - 1] = tmp;
		}
	}
	vector< vector<int> > pi;
	for (int i = 0; i < len[0] - K + 1; i++)
		pi.push_back(getpi(code[0], i));
	bool virus;
	for (int t = 0; t < len[0] - K + 1; t++)
	{
		virus = 1;
		for (int num = 1; num < N && virus; num++)
		{
			if (!kmp(code[num], code[0], t, pi[t]) && !kmp(rcode[num], code[0], t, pi[t]))
				virus = 0;
		}
		if (virus == 1)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return (0);
}

