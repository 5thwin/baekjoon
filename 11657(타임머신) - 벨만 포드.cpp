#include <iostream>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF  99987654321
#define MP make_pair
using namespace std;

int N, M;
bool isNegativeCycle; 
vector<pair<int, long long>> adj[501];

vector<long long> bellmanFord(int src)
{
	//  시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로 둔다.
	vector<long long> Dist(N + 1, INF);
	Dist[src] = 0;
	bool updated;
	isNegativeCycle = false;
	//V번 순회
	for (int iter = 0; iter < N; iter++)
	{
		updated = false;
		for (int node = 0; node < N; node++)
		{
			if (Dist[node] == INF) 
				continue;
			int len = adj[node].size();
			for (int i = 0; i < len; i++)
			{
				int next = adj[node][i].first;
				int cost = adj[node][i].second;

				if (Dist[next] > Dist[node] + cost)
				{
					Dist[next] = Dist[node] + cost;
					updated = true;
				}
			}
		}
		//  모든 간선에 대해 완화가 실패했을 경우 V-1번도 돌 필요 없이 곧장 종료
		if (updated == false)
			break;
	}
	//  V번째 순회에서도 완화가 성공했다면 음수 사이클이 있음
	if (updated)
	{
		isNegativeCycle = true;
		Dist.clear();
	}
	return Dist;

}
int main()
{
	FAST;
	int A, B;
	long long C;
	vector<long long> Dist;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A - 1].push_back(MP(B - 1, C));
	}
	Dist = bellmanFord(0);
	if (isNegativeCycle)
		cout << "-1";
	else
	{
		for (int i = 1; i < N; i++)
		{
			cout << (Dist[i] != INF ? Dist[i] : -1) << "\n";
		}
	}
}