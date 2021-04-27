#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int N;
vector<int> tvec;
vector<int> dp;
vector< vector<int> > graph;
vector< vector<int> > prework;

int solve(int n)
{
	int &ret = dp[n];
	if (ret != -1)
		return ret;
	ret = 0;
	int len = prework[n].size();
	for (int i = 0; i < len; i++)
	{
		int pre = prework[n][i];
		ret = max(ret, solve(pre));
	}
	ret += tvec[n];
	return ret;
}
int main() {
	FAST;
	cin >> N;
	dp.resize(N, -1);
	tvec.resize(N);
	graph.resize(N, vector<int>());
	prework.resize(N, vector<int>());
	for (int i = 0; i < N; i++)
	{
		cin >> tvec[i];
		int cnt, pre;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			cin >> pre;
			prework[i].push_back(pre - 1);
			graph[pre - 1].push_back(i);
		}
	}
	int ans = -1;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, solve(i));
	}
	cout << ans;
}

