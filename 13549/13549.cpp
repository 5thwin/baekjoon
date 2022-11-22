#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair

typedef long long ll;
using namespace std;

int N, K;							// 수빈이 위치 동생의 위치
int dist[100001];					// dist[a] : N에서 a 위치까지 수빈이가 가는 최단거리
priority_queue<pair<int, int>> adj; // adj (거리, 위치) 근데 거리는 음수로 넣을 예정
// 근데 순간이동은 0초 걸림
void checkAndUpdate(int curPos, int nextPos, int sec)
{
	if (dist[nextPos] == -1 || dist[nextPos] > dist[curPos] + sec) //아직 탐색하지 않은 자리거나, 탐색은 했는데 이전보다 더 짧은 경로를 찾았다면
	{
		dist[nextPos] = dist[curPos] + sec;
		adj.push(MP(-dist[nextPos], nextPos));
	}
}
void dijkstra()
{
	adj.push(MP(0, N));
	dist[N] = 0;
	while (!adj.empty())
	{
		pair<int, int> cur = adj.top();
		int curDist = -cur.first;
		int curPos = cur.second;
		adj.pop();
		//만약 현재 꺼낸 위치와 거리보다 더 최단거리로 dist에 업데이트 되면 skip
		if (dist[curPos] < curDist)
			continue;
		//한칸 앞으로 +1 :1초 걸림
		if (curPos + 1 <= 100000)
			checkAndUpdate(curPos, curPos + 1, 1);
		//한칸 뒤로 -1 : 1초걸림
		if (curPos - 1 >= 0)
			checkAndUpdate(curPos, curPos - 1, 1);
		//순간이동 *2 : 0초걸림
		if (2 * curPos <= 100000)
			checkAndUpdate(curPos, curPos * 2, 0);
	}
	return;
}

int main()
{
	FAST;
	freopen("../../input.txt", "r", stdin);
	cin >> N >> K;
	memset(dist, -1, sizeof(dist));
	dijkstra();
	cout << dist[K];
}
