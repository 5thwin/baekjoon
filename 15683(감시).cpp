#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MP make_pair
using namespace std;

/*
0 ->
1 <->
2 ㄴ
3 ㅏ
4 +
*/
int N, M, not_shoot, map[8][8], angle[8]; //0 1 2 3 -> 0,90,180,270
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = { 0, -1, 0, 1 };
vector<pair<int, pair<int, int>>> cctv;

int one_direction(int dir_idx, int (*visit)[8], int ctv_idx)
{
	int shoot_spot = 0;
	int y = cctv[ctv_idx].second.first;
	int x = cctv[ctv_idx].second.second;
	while (1)
	{
		if (x < 0 || y < 0 || x >= M || y >= N)
			break;
		if (map[y][x] == 6)
			break;
		if (visit[y][x] == 0)
		{
			shoot_spot++;
			visit[y][x] = 1;
		}
		x += dir_x[dir_idx];
		y += dir_y[dir_idx];
	}
	return shoot_spot;
}
int standby(int num, int ang, int ctv_idx, int (*visit)[8])
{
	int shoot_spot = 0;
	if (num == 1)
	{
		if (ang == 0)
			shoot_spot += one_direction(0, visit, ctv_idx); // dir_idx 0 : 우
		if (ang == 1)
			shoot_spot += one_direction(1, visit, ctv_idx); // dir_idx 1 : 하
		if (ang == 2)
			shoot_spot += one_direction(2, visit, ctv_idx); // dir_idx 2 : 좌
		if (ang == 3)
			shoot_spot += one_direction(3, visit, ctv_idx); // dir_idx 3 : 상
	}
	if (num == 2)
	{
		if (ang == 0 || ang == 2)
		{
			shoot_spot += one_direction(0, visit, ctv_idx); // dir_idx 0 : 우
			shoot_spot += one_direction(2, visit, ctv_idx); // dir_idx 2 : 좌
		}
		if (ang == 1 || ang == 3)
		{
			shoot_spot += one_direction(1, visit, ctv_idx); // dir_idx 1 : 하
			shoot_spot += one_direction(3, visit, ctv_idx); // dir_idx 3 : 상
		}
	}
	if (num == 3)
	{
		if (ang == 0)
		{
			shoot_spot += one_direction(0, visit, ctv_idx); // dir_idx 0 : 우
			shoot_spot += one_direction(3, visit, ctv_idx); // dir_idx 3 : 상
		}
		if (ang == 1)
		{
			shoot_spot += one_direction(1, visit, ctv_idx); // dir_idx 1 : 하
			shoot_spot += one_direction(0, visit, ctv_idx); // dir_idx 0 : 우
		}
		if (ang == 2)
		{
			shoot_spot += one_direction(2, visit, ctv_idx); // dir_idx 2 : 좌
			shoot_spot += one_direction(1, visit, ctv_idx); // dir_idx 1 : 하
		}
		if (ang == 3)
		{
			shoot_spot += one_direction(3, visit, ctv_idx); // dir_idx 3 : 상
			shoot_spot += one_direction(2, visit, ctv_idx); // dir_idx 2 : 좌
		}
	}
	if (num == 4)
	{
		if (ang == 0)
		{
			shoot_spot += one_direction(0, visit, ctv_idx); // dir_idx 0 : 우
			shoot_spot += one_direction(3, visit, ctv_idx); // dir_idx 3 : 상
			shoot_spot += one_direction(1, visit, ctv_idx); // dir_idx 1 : 하
		}
		if (ang == 1)
		{
			shoot_spot += one_direction(1, visit, ctv_idx); // dir_idx 1 : 하
			shoot_spot += one_direction(0, visit, ctv_idx); // dir_idx 0 : 우
			shoot_spot += one_direction(2, visit, ctv_idx); // dir_idx 2 : 좌
		}
		if (ang == 2)
		{
			shoot_spot += one_direction(2, visit, ctv_idx); // dir_idx 2 : 좌
			shoot_spot += one_direction(1, visit, ctv_idx); // dir_idx 1 : 하
			shoot_spot += one_direction(3, visit, ctv_idx); // dir_idx 3 : 상
		}
		if (ang == 3)
		{
			shoot_spot += one_direction(3, visit, ctv_idx); // dir_idx 3 : 상
			shoot_spot += one_direction(2, visit, ctv_idx); // dir_idx 2 : 좌
			shoot_spot += one_direction(0, visit, ctv_idx); // dir_idx 0 : 우
		}
	}
	if (num == 5)
	{
		shoot_spot += one_direction(0, visit, ctv_idx); // dir_idx 0 : 우
		shoot_spot += one_direction(3, visit, ctv_idx); // dir_idx 3 : 상
		shoot_spot += one_direction(1, visit, ctv_idx); // dir_idx 1 : 하
		shoot_spot += one_direction(2, visit, ctv_idx); // dir_idx 2 : 좌
	}
	return (shoot_spot);
}
int blind_cnt(int cctv_count)
{
	int num, ang;
	int visit[8][8];
	int shoot_spot = 0;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < cctv_count; i++)
	{
		num = cctv[i].first;
		ang = angle[i];
		shoot_spot += standby(num, ang, i, visit);
	}
	return (not_shoot - shoot_spot);
}

int dfs_angle(int n, int cctv_count)
{
	int blind = not_shoot;
	if (n == cctv_count) /*모든 cctv의 각도를 정함*/
		return (blind_cnt(cctv_count));
	for (int i = 0; i < 4; i++)  // i = 0,1,2,3 -> 0,90,180,270 회전
	{
		if (i >= 2 && cctv[n].first == 2)
			continue;
		if (i >= 1 && cctv[n].first == 5)
			continue;
		angle[n] = i; //각도를 정함
		blind = min(blind, dfs_angle(n + 1, cctv_count));
	}
	return (blind);
}
int main()
{
	scanf("%d %d", &N, &M);
	not_shoot = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] <= 5 && map[i][j] >= 1)
				cctv.push_back(MP(map[i][j], MP(i, j)));
			if (map[i][j] != 6)
				not_shoot++;
		}
	}
	printf("%d", dfs_angle(0, cctv.size()));
}