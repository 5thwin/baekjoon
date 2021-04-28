#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
using namespace std;

int N, Maxdept;
vector< vector<pair<int, int> > > tree;
vector< vector<int> >Anct; //Anct[n][i] = n번 노드의 2^i번째 조상
vector<int> Dept;
vector<vector<int> > maxdist;
vector<vector<int> > mindist;
void getTree(int n, int parent)
{
	if (parent != -1)
		Dept[n] = Dept[parent] + 1;
	Anct[n][0] = parent;
	int p = parent;
	/*조상 업데이트*/
	for (int i = 1; i < Maxdept && p >= 0; i++)
	{
		Anct[n][i] = Anct[p][i-1];
		p = Anct[p][i-1];
	}
	/*DFS*/
	int len = tree[n].size();
	for (int i = 0; i < len; i++)
	{
		int there = tree[n][i].first;
		if (there == parent)
			continue;
		getTree(there, n);
	}
	return;
}
int ft_lca(int u, int v)
{
	int a = u, b = v;
	if (Dept[a] > Dept[b])
		swap(a , b); /* 깊이 a < 깊이 b*/
	int tmp;
	/*같은 깊이가 되도록 b를 올리기*/
	while (Dept[a] != Dept[b])
	{
		for (int i = Maxdept - 1; i >= 0; i--)
		{
			tmp = Anct[b][i];
			if (tmp == -1)
				continue;
			if (Dept[tmp] < Dept[a])
				continue;
			b = tmp;
		}
	}
	/*높이를 올려가며 최대 공통 조상 찾기*/
	int lca = a;
	for (int i = Maxdept - 1; i >= 0 && a != b; i--)
	{
		if (Anct[a][i] == Anct[b][i])
		{
			lca = Anct[a][i];
			continue;
		}
		a = Anct[a][i];
		b = Anct[b][i];
	}
	return lca;
}
void find_m(int a, int lca, int *maxdist, int *mindist)
{
	while (a != lca)
	{
		int len = tree[a].size();
		for (int i = 0; i < len; i++)
		{
			int there = tree[a][i].first;
			if (there != Anct[a][0])
				continue;
			*maxdist = max(*maxdist, tree[a][i].second);
			*mindist = min(*mindist, tree[a][i].second);
			a = there;
			break;
		}
	}
}
int main() {
	FAST; cin >> N;
	int a, b, c, K;
	tree.resize(N);
	Maxdept = log2(N) + 1;
	Anct.resize(N, vector<int>(Maxdept, -1));
	Dept.resize(N);
	maxdist.resize(N, vector<int>(Maxdept, -1));
	mindist.resize(N, vector<int>(Maxdept, -1));
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> c;
		a--; b--;
		tree[a].push_back(MP(b, c));
		tree[b].push_back(MP(a, c));
	}
	getTree(0, -1);
	cin >> K;
	while (K--)
	{
		cin >> a >> b;
		a--,b--;
		c = ft_lca(a, b);
		int maxd = -1, mind = 1000001;
		find_m(a,c,&maxd, &mind);
		find_m(b,c,&maxd, &mind);
		cout << maxd << " " << mind << "\n";
	}
}

