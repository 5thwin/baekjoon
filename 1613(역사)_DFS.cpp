//DFS
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<int> adj[400];
bool visit[400];
int dfs(int src, int dst) {
	visit[src] = true;
	for (int i = 0; i < adj[src].size(); i++) {
		int next = adj[src][i];
		if (next == dst)
			return 1;
		if (!visit[next]) {
			if (dfs(next, dst) == 1)
				return 1;
		}
	}
	return 0;
}
int main() {
	int N, E, a, b, s, i;
	scanf("%d %d", &N, &E);
	for (i = 0; i < E; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
	}
	scanf("%d", &s);
	for (i = 0; i < s; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		memset(visit, 0, sizeof(visit));
		if (dfs(a, b) == 1) {
			printf("-1\n");
			continue;
		}
		memset(visit, 0, sizeof(visit));
		if (dfs(b, a) == 1) {
			printf("1\n");
			continue;
		}
		printf("0\n");
	}
}