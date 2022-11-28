#include <iostream>
#include <vector>
#include <algorithm>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair

typedef long long ll;
using namespace std;

int N, M; // N 손님수 M 최종 목적지
vector<pair<int, int>> rev;
bool compair(pair<int, int> &a, pair<int, int> &b)
{
	return a.second > b.second;
}
int main()
{
	FAST;
	// freopen("../../input.txt", "r", stdin);
	cin >> N >> M;
	ll src, des;
	ll overlap_dist = 0; //거꾸로 되돌아와야 하는 거리
	for (int i = 0; i < N; i++)
	{
		cin >> src >> des;
		if (des >= src) //정방향 손님은 무시
		{
			continue;
		}
		rev.push_back(MP(des, src));
	}
	sort(rev.begin(), rev.end(), compair);

	ll overlab_right = 0, overlab_left = 0;

	for (auto iter = rev.begin(); iter != rev.end(); iter++)
	{
		ll right = (*iter).second;
		ll left = (*iter).first;
		if (iter == rev.begin()) //첫 시작점
		{
			overlab_right = right;
			overlab_left = left;
			continue;
		}
		/*겹치는 부분이 있는지 확인*/
		if (right >= overlab_left)
		{ //겹친다면 overlab 길이 갱신
			if (left < overlab_left)
				overlab_left = left;
			continue;
		}
		//겹치지 않는다면 기존 overlab를 처리하고 새로 overlab 구간 갱신
		overlap_dist += (overlab_right - overlab_left);
		overlab_right = right;
		overlab_left = left;
	}

	overlap_dist += (overlab_right - overlab_left);
	cout << 2 * overlap_dist + M;
}
