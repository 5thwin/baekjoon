//Floyd-Warshall Algorithm
#include<cstdio>
#include<vector>
#define INF 999999999
using namespace std;

int adj[400][400];

int main() {
	int N, E, a,b,s;
	scanf("%d %d", &N, &E);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			adj[i][j] = INF;
		}
	}
	
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		adj[a][b] = 1;
	}

	//here로 갈 수 있는 노드는, here에서 갈수있는 노드들로 향하는 엣지를 추가
	for (int here = 0; here < N; here++) {
		for (int src = 0; src < N; src++){
			for (int dst = 0; dst < N; dst++) {
				if (adj[src][dst] > adj[src][here] + adj[here][dst]) {
					adj[src][dst] = adj[src][here] + adj[here][dst];
				}
			}
		}
	}
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		if (adj[a][b]<INF)
			printf("-1\n");
		else if (adj[b][a]<INF)
			printf("1\n");
		else
			printf("0\n");
	}
}