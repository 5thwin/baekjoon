//BFS
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

vector<int> adj[400];
bool visit[400];

int bfs(int src, int dst) {
	queue<int> q;
	q.push(src);
	visit[src] = true;
	while (!q.empty()) {
		int here = q.front();

		q.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			if (next == dst)
				return 1;
			if (!visit[next]) {
				q.push(next);
				visit[next] = true;
			}
		}
	}
	return 0;
}
int main() {
	int N, E, a, b, s,i;
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
		if (bfs(a, b) == 1)
		{
			printf("-1\n");
			continue;
		}
		memset(visit, 0, sizeof(visit));
		if (bfs(b, a) == 1)
		{
			printf("1\n");
			continue;
		}
		printf("0\n");
	}
}