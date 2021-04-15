#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF  987654321
#define MP make_pair
using namespace std;

int T, N, M, K;

struct Ticket
{
	int src;
	int dst;
	int cost;
	int time;
	Ticket(int s, int d, int c, int t)
	{
		src = s; dst = d; cost = c; time = t;
	}
};

struct Cmp
{
	bool operator()(const Ticket& A, const Ticket& B)
	{
		if (A.time == B.time)
		{
			return (A.cost > B.cost);
		}
		return (A.time > B.time);
	}
};
vector<vector<Ticket>> adj;

vector<vector<int>> Dij()
{
	priority_queue<Ticket, vector<Ticket>, Cmp> pq;
	vector<vector<int>> dist; //시간
	dist.resize(N + 1, vector<int>(M + 1,INF));
	pq.push(Ticket(1,1,0,0));
	while (!pq.empty())
	{
		int cur = pq.top().dst;
		int ccost = pq.top().cost;
		int ctime = pq.top().time;
		pq.pop();
		if (dist[cur][ccost] < ctime)
			continue;
		int len = adj[cur].size();
		for (int i = 0; i < len; i++)
		{
			int next = adj[cur][i].dst;
			int ncost = adj[cur][i].cost;
			int ntime = adj[cur][i].time;
			if (ncost + ccost > M)
				continue;
			if (ntime + ctime >= dist[next][ncost + ccost])
				continue;
			for (int j = ncost + ccost; j <= M; j++) /*무의미한 계산을 방지하기 위해서, 그 이상의 비용에 대해 전부 업데이트*/
			{
				if (dist[next][j] > ntime + ctime)
					dist[next][j] = ntime + ctime;
			}
			pq.push(Ticket(cur, next, ncost + ccost, ntime + ctime));
		}
	}
	return dist;
}
int main()
{
	FAST;
	int u, v, c, t, ans = INF;
	cin >> T;
	vector<vector<int>> dist;
	while (T--)
	{
		ans = INF;
		cin >> N >> M >> K;
		adj.clear();
		adj.resize(N + 1);
		for (int i = 0; i < K; i++)
		{
			cin >> u >> v >> c >> t;
			adj[u].push_back(Ticket(u, v, c, t));
		}
		dist = Dij();
		for (int i = 0; i <= M; i++)
		{
			ans = min(ans, dist[N][i]);
		}
		if (ans != INF)
			cout << ans << "\n";
		else
			cout << "Poor KCM\n";
		dist.clear();
	}
}
/*
1
6 149 8
1 2 60 20
2 3 30 70
1 3 100 80
1 3 20 180
3 4 20 100
3 5 150 20
5 6 50 40
4 6 30 50
240
*/