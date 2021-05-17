#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

vector<int> getPi(string str)
{
	int i, j = 0;
	int len = str.size();
	vector<int> pi(len, 0);
	for (i = 1; i < len; i++)
	{
		while (j > 0 && str[i] != str[j]) //같지 않다면 인덱스를 앞으로 당긴다.
			j = pi[j - 1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string T, string P)
{
	vector<int> pi = getPi(P);
	vector<int> ret;
	int tlen = T.size();
	int plen = P.size();
	int i, j = 0;
	for (i = 0; i < tlen; i++)
	{
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];
		if (T[i] == P[j])
		{
			if (j == plen - 1)
			{
				ret.push_back(i - j);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return (ret);
}

int main() {
	FAST;
	string T, P;
	getline(cin, T);
	getline(cin, P);
	vector<int> answer = kmp(T, P);
	int cnt = answer.size();
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
		cout << answer[i] + 1<< " ";
}

