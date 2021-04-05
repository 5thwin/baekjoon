#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
#define OTH(X) (X) == 1 ? 0 : 1
using namespace std;

int N, K;
char map[2][100001];
bool visit[2][100001];
int BFS(int i, int rdnum)
{
	queue<pair<pair<int, int>, int>> qu;
	qu.push(MP(MP(i, rdnum), 0));
	int ci, cnum, ctime;
	while (!qu.empty())
	{
		ci = qu.front().first.first;
		cnum = qu.front().first.second;
		ctime = qu.front().second;
		qu.pop();
		if (ci < ctime)
			continue;
		if (ci >= N - K) //한칸 앞으로 혹은 점프하면 게임 클리어
			return (1);
		if (visit[cnum][ci] == 1)
			continue;
		visit[cnum][ci] = 1;

		/*앞으로 한 칸 이동*/
		if (map[cnum][ci + 1] == '1' && visit[cnum][ci + 1] == 0)
			qu.push(MP(MP(ci + 1, cnum), ctime + 1));
		/*뒤로 한 칸 이동*/
		if (ci > 0) {
			if (map[cnum][ci - 1] == '1' && visit[cnum][ci - 1] == 0)
				qu.push(MP(MP(ci - 1, cnum), ctime + 1));
		}
		/*반대편으로 점프*/
		if (map[OTH(cnum)][ci + K] == '1' && visit[OTH(cnum)][ci + K] == 0)
			qu.push(MP(MP(ci + K, OTH(cnum)), ctime + 1));
	}
	return (0);
}
int main()
{
	FAST;
	cin >> N >> K;
	cin >> map[0];
	cin >> map[1];
	cout << BFS(0, 0);
}