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
int dp[1000001][2];			   //dp[n][k] : n이 k(얼리어답트)일때, 필요한 최소 얼리어답트수
int solve(int n, int p, int k) //p = 부모
{
	int &ret = dp[n][k];
	if (ret != -1)
		return ret;
	int len = tree[n].size();
	vector<int> child_vec; // 자식들을 저장할 벡터
	for (int i = 0; i < len; i++)
	{
		int there = tree[n][i];
		if (there == p)
			continue;
		child_vec.push_back(there);
	}
	if (child_vec.size() == 0) //자식이 존재하지 않음 ; leaf 노드
	{
		dp[n][0] = 0;
		dp[n][1] = 1;
		return ret;
	}
	len = child_vec.size();
	ret = 0;
	if (k == 0) //자신이 얼리어답트가 아니라면 자식들은 모두 얼리어답트여야함
	{
		for (int i = 0; i < len; i++)
		{
			int child = child_vec[i];
			ret += solve(child, n, 1);
		}
		return ret;
	}
	else //자신이 얼리어답트라면 자식들이 얼리어답트일때와 아닐때중 최소의 경우를 고른다.
	{
		for (int i = 0; i < len; i++)
		{
			int child = child_vec[i];
			ret += min(solve(child, n, 1), solve(child, n, 0));
		}
		ret += 1;
		return ret;
	}
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
