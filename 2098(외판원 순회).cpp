#include<iostream>
#include<cstring>
#include<algorithm>

#define MAX_VAL 987654321

using namespace std;

int N, ALL_VISIT;
int dist[16][16], dp[16][65535];
int tsp(int now, int visited) {
	int& ret = dp[now][visited];
	if (visited == ALL_VISIT) {
		if (dist[now][0] == 0)
			return ret = MAX_VAL;
		return ret = dist[now][0];
	}
	if (ret != 0)
		return ret;

	ret = MAX_VAL;
	for (int next = 1; next < N; next++) {
		if (visited & (1 << next))
			continue;
		if (dist[now][next] == 0)
			continue;
		ret = min(ret, tsp(next, visited | (1 << next)) + dist[now][next]);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	ALL_VISIT = (1<<N) - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
		}
	}
	cout << tsp(0, 1) << '\n';// 처음 시작점 0번

}