#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
#define INF 2147483647
typedef long long ll;
using namespace std;

int N, M;
vector< vector<pair<int, int> > > graph;
vector<int> dijstra(int start)
{
	vector<int> ret(N + 1, INF);
	priority_queue<pair<int, int> > pq;
	pq.push(MP(0, start));
	ret[start] = 0;
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > ret[here])
			continue;
		int len = graph[here].size();
		for (int i = 0; i < len; i++)
		{
			int there = graph[here][i].first;
			int ncost = cost + graph[here][i].second;
			if (ncost > ret[there])
				continue;
			ret[there] = ncost;
			pq.push(MP(-ncost, there));
		}
	}
	return ret;
}
int dp[1001]; //dp[n] : n에서 출발하여 T 에 도달할 수 있는 합리적경로
int S = 1, T = 2;
int solve(int n, vector<int> dist)
{
	int &ret = dp[n];
	if (ret != -1)
		return ret;
	if (n == T)
		return ret = 1;
	ret = 0;
	int len = graph[n].size();
	for (int i = 0; i < len; i++)
	{
		int there = graph[n][i].first; //n번노드에 연결된 노드
		if (dist[there] >= dist[n]) //합리적경로 아님(더 멀어짐)
			continue;
		ret += solve(there, dist);
	}
	return ret;
}
int main() {
	FAST;
	cin >> N >> M;
	graph.resize(N + 1, vector<pair<int,int> >());
	memset(dp, -1, sizeof(dp));
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back(MP(b, c));
		graph[b].push_back(MP(a, c));
	}
	vector<int> dist = dijstra(T);
	cout << solve(S, dist);
}

