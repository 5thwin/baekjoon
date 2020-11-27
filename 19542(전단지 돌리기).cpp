#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> visit;
int node_cnt; //거쳐야할 노드의 개수
int N, S, D;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int dfs(int node, int depth)
{
	int next;
	int maxdp = depth;
	for (int i = 0; i < tree[node].size(); i++)
	{
		next = tree[node][i];
		if (visit[next] == 0)
		{
			visit[next] = 1;
			maxdp = max(maxdp, dfs(next, depth + 1));
		}
	}
	if (maxdp == depth)
	{	//node는 leaf
		if (D == 0)
			node_cnt++;
	}
	else if (maxdp - depth >= D)
		node_cnt++;
	return maxdp;
}
int main()
{
	int s, d;
	scanf("%d %d %d", &N, &S, &D);
	tree.resize(N + 1, vector<int>());
	visit.resize(N + 1, 0);
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &s, &d);
		tree[s].push_back(d);
		tree[d].push_back(s);
	}
	visit[S] = 1;
	dfs(S, 0);
	if (node_cnt > 0)
		printf("%d", (node_cnt - 1) * 2);
	else
		printf("0");
}

/*
8 1 2
1 2
1 3
2 4
2 5
3 6
4 7
5 8
*/