#include<iostream>
#include<string.h>
#include<cstring>
#include<vector>
using namespace std;

string s1, s2;
vector<vector<int>> dp;

int d_min(int a, int b)
{
	return a < b ? a : b;
}
int t_min(int a, int b, int c)
{
	return d_min(d_min(a, b), c);
}
bool match(char c1, char c2)
{
	if (c1 == c2)
		return 1;
	if (c1 == 'i' && (c2 == 'j' || c2 == 'l'))
		return 1;
	if (c1 == 'v' && c2 == 'w')
		return 1;
	return 0;
}
int solve(int n, int m)
{
	if (n < 0 && m < 0) return 0; //동시에 끝난 경우
	if (n < 0) return m + 1;
	if (m < 0) return n + 1;
	int& ret = dp[n][m];
	if (ret != -1)
		return ret;
	if (match(s1[n], s2[m]))
		return ret = solve(n - 1,m - 1);
	return ret = t_min(solve(n - 1,m) + 1, solve(n,m - 1) + 1, solve(n - 1 , m - 1) + 1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	cin >> s1;
	cin >> s2;
	dp.assign(n, vector<int>(m, -1));
	printf("%d", solve(n - 1, m - 1));
}