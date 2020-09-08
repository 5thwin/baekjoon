#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int N, M;
int dx[4] = { 1,-1,0,0 }, dy[4] = {0, 0, 1, -1}; //오른쪽,왼쪽,위,아래
string map[100];
queue<pair<pair<int, int>,int>> qu;
bool visit[100][100];
int bfs() {
	pair<int, int> now;
	int dist,posx, posy, nx,ny;
	qu.push({ { 0,0 },1 });
	visit[0][0] = true;
	while (!qu.empty()) {
		now = qu.front().first;
		dist = qu.front().second;
		qu.pop();
		posy = now.first;
		posx = now.second;
		for (int i = 0; i < 4; i++) {
			nx = posx + dx[i], ny = posy + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (map[ny][nx] == '0')
				continue;
			if (visit[ny][nx] != 0)
				continue;
			qu.push({ { ny,nx }, dist + 1 });
			visit[ny][nx] = true;
		}
		if (posx == M-1 && posy == N-1)
			return dist;
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	
	cout << bfs();
}
