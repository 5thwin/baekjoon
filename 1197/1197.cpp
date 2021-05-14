#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

struct Edge
{
	int c;
	int s;
	int d;
	Edge(int _c, int _s, int _d)
	{
		c = _c;
		s = _s;
		d = _d;
	}
};

struct Cmp
{
	bool operator()(const Edge &a, const Edge &b)
	{
		return (a.c > b.c);
	}
};

int V, E;
int A, B, C;
vector<int> id;
priority_queue<Edge, vector<Edge>, Cmp> pq;

int find(int x)
{
	if (id[x] < 0) return x;
	return id[x] = find(id[x]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return (0);
	id[a] = b;
	return (1);
}

int main() {
	FAST;
	cin >> V >> E;
	id.resize(V + 1, -1);
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		pq.push(Edge(C, A, B));
	}
	int cost_sum = 0;
	int mst_edge = 0;
	while (!pq.empty())
	{
		int cost = pq.top().c;
		int a = pq.top().s;
		int b = pq.top().d;
		pq.pop();
		if (merge(a, b))
		{
			cost_sum += cost;
			mst_edge++;
		}
		if (mst_edge == V - 1)
			break;
	}
	cout << cost_sum;
}

