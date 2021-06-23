#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;


int main() {
	FAST;
	int N, a, b;
	vector<pair<int, int> > meeting;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		meeting.push_back(MP(a, b));
	}
	sort(meeting.begin(), meeting.end());
	int result = 1, last = meeting[0].second;
	for (int i = 1; i < N; i++)
	{
		int start = meeting[i].first;
		int end = meeting[i].second;
		if (last > start) //가장 마지막에 끝나는 회의시간이 다음오는 회의시작시간보다 늦을 때
		{
			if (end < last) //끝나는 시간을 보고 먼저 끝나는 회의를 선택
				last = end;
		}
		else //새 회의 시작시간이 이전회의끝난 이후일때
		{
			result++;
			last = end;
		}
	}
	cout << result;
}

