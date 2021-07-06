#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int N, M;
vector<vector<int> > graph, rgraph;

vector<bool> bfs(int s, vector<vector<int> > map)
{
	queue<int> qu;
	vector<bool> visit(N + 1, 0);
	visit[s] = 1;
	qu.push(s);
	while (!qu.empty())
	{
		int here = qu.front();
		qu.pop();
		int len = map[here].size();
		for (int i = 0; i < len; i++)
		{
			int there = map[here][i];
			if (visit[there])
				continue;
			visit[there] = 1;
			qu.push(there);
		}
	}
	return visit;
}
int main() {
	FAST;
	int u,v;
	cin >> N >> M;
	graph.resize(N + 1);
	rgraph.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		rgraph[v].push_back(u);
	}
	vector<bool> visit = bfs(1, graph);
	vector<bool> rvisit = bfs(N, rgraph);
	int T, bomb;
	cin >> T;
	while (T--)
	{
		cin >> bomb;
		if (visit[bomb] && rvisit[bomb])
			cout << "Defend the CTP\n";
		else
			cout << "Destroyed the CTP\n";
	}

}

