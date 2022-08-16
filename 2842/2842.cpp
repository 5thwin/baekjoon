#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

string map[50];
int hmap[50][50], N, sy, sx, house; //고도맵, 시작위치 y,x좌표, 집 개수
vector<int> height; //모든 고도를 중복없이 저장할 벡터
bool exist_check[1000001]; //중복을 없애서 저장하기 위해 나온 높이는 표시

bool bfs(int low, int upper)
{
	queue<pair<int, int> > qu;
	bool visit[50][50];
	int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}; //오른쪽방향부터 시계방향
	int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	int vhouse = 0; //방문한 집들 카운트

	if (hmap[sy][sx] < low || hmap[sy][sx] > upper) // 우체국의 높이가 범위 밖
		return false;
	memset(visit, 0 ,sizeof(visit));
	visit[sy][sx] = 1;
	qu.push(MP(sy, sx));
	while (!qu.empty())
	{
		int cy = qu.front().first;
		int cx = qu.front().second;
		qu.pop();
		if (map[cy][cx] == 'K')
			vhouse++;
		if (vhouse == house) //모든 집들 방문
			return true;
		for (int i = 0; i < 8; i++) //인접한 지점 탐색
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visit[ny][nx] || hmap[ny][nx] < low || hmap[ny][nx] > upper) //이미 방문한 점이거나, 고도가 범위 밖이면 무시
				continue;
			visit[ny][nx] = 1;
			qu.push(MP(ny, nx));
		}
	}
	return false;
}

int main() {
	FAST;
	int hsize = 0;
	house = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
		for (int j = 0; j < N; j++)
		{
			if (map[i][j]== 'P') //우체국위치
			{
				sy = i, sx = j;
			}
			else if (map[i][j] == 'K')
				house++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> hmap[i][j];
			if (!exist_check[hmap[i][j]])
			{
				exist_check[hmap[i][j]] = 1;
				height.push_back(hmap[i][j]);
				hsize++;
			}
		}
	}
	sort(height.begin(), height.end()); //정렬

	/*low와 upper 사이의 고도값만 밟고 이동가능한지 보기*/
	int lid = 0, uid = 0, answer = 1000001;
	while (uid < hsize)
	{
		if (lid > uid)
		{
			uid++;
			continue;
		}
		int low = height[lid], upper = height[uid];
		if (bfs(low, upper)) //low와 upper 범위 내에서 갈 수 있을 때
		{
			answer = min(answer, upper - low);
			lid++;
		}
		else //범위 내의 고도만 밟고 갈수 없을 때
			uid++;
	}
	cout << answer;
}

