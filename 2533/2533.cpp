#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);

typedef long long ll;
using namespace std;

vector<vector<int> > tree;
int dp[1000001][2];			   //dp[n][k] : n이 k(얼리)일때, 필요한 최소 얼리어답트수
int solve(int n, int p, int k) //p = 부모
{
	int &ret = dp[n][k];
	if (ret != -1)
		return ret;
	ret = k;
	int len = tree[n].size();
	for (int i = 0; i < len; i++)
	{
		int there = tree[n][i];
		if (there == p)
			continue;
		if (k == 0) //내가 얼리가 아니면 자식들은 모두 얼리여야함
			ret += solve(there, n, 1);
		else if (k == 1) //내가 얼리면 자식들은 얼리일떄와 아닐때 중 최소를 선택
			ret += min( solve(there, n, 1), solve(there, n, 0));
	}
	/*자식이 없는 경우: 자신이 얼리면 1, 아니면 0*/
	return ret;
}
int main()
{
	FAST;
	int N, a, b;
	cin >> N;
	memset(dp, -1, sizeof(dp));
	tree.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cout << min(solve(1,0,0), solve(1,0,1));
}
