#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
#define INF 987654321
#define MAX_NODE 40000
#define swap(a,b){int t = a; a = b; b = t;}

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> depth; // �� ������ ���̸� ����
vector<vector<int>> ac; // ac[n][i] : n������� 2 ^ i ��° ����

vector<int> DistRoot;
int max_level;
int N, M;


void get_Tree(int here, int parent)
{
	depth[here] = depth[parent] + 1;
	
	ac[here][0] = parent;

	/*���� ������Ʈ*/
	for (int i = 1; i <= max_level; i++)
	{
		int ances = ac[here][i - 1];
		ac[here][i] = ac[ances][i - 1];
	}
	/*DFS�� Ʈ�������*/
	int len = graph[here].size();
	for (int i = 0; i < len; i++)
	{
		int there = graph[here][i].first;
		if (there == parent)
			continue;
		get_Tree(there, here);
	}
}
int LCA(int a, int b)
{
	if (depth[a] < depth[b]) //a�� ���̰� b�� ���̺��� ũ��.
		swap(a, b);
	if (depth[a] != depth[b])
	{
		for (int i = max_level; i >= 0; i--) //a�� b�� ���̰� ���������� a�� ��� �ø�
		{
			if (depth[ac[a][i]] < depth[b])
				continue;
			a = ac[a][i];
		}
	}
	//���̰� ������ ���� ������������ ��� �θ� ���� ��, �ö󰥶��� 2�� �¼���ŭ�� �ö�
	int dist = 0;
	int lca = a;
	if (a != b)
	{
		for (int i = max_level; i >= 0; i--)
		{
			if (ac[a][i] != ac[b][i])
			{
				a = ac[a][i];
				b = ac[b][i];
			}
			lca = ac[a][i];
		}
	}

	return lca;
}
void BFS(int start)
{
	queue<pair<int, int>> qu;
	qu.push(MP(start, 0));
	while (!qu.empty())
	{
		int here = qu.front().first;
		int dist = qu.front().second;
		qu.pop();
		if (DistRoot[here] != -1)
			continue;
		DistRoot[here] = dist;
		int len = graph[here].size();
		for (int i = 0; i < len; i++)
		{
			int there = graph[here][i].first;
			int ndist = dist + graph[here][i].second;
			if (DistRoot[there] != -1)
				continue;
			qu.push(MP(there, ndist));
		}
	}
}
int main()
{
	FAST; cin >> N;
	graph.resize(N + 1);
	depth.resize(N + 1);
	max_level = (int)log2(N);
	ac.resize(N + 1, vector<int>(max_level + 1, 0));
	DistRoot.resize(N + 1, -1);

	int u, v, w;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(MP(v, w));
		graph[v].push_back(MP(u, w));
	}
	/*1�� ��尡 root�� Ʈ���� �����.*/
	depth[0] = -1;
	get_Tree(1, 0);
	BFS(1);
	cin >> M;
	while (M--)
	{
		cin >> u >> v;
		int lca = LCA(u, v);
		cout << DistRoot[u] + DistRoot[v] - 2 * DistRoot[lca] << "\n";
	}
}