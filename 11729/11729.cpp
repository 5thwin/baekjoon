#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;
/*
3칸짜리 3번에 탑을 이동시키려면
 : 2칸짜리 탑을 2번에 이동시킨후, 마지막 원판을 3번에 놓은 후, 2칸짜리를 3번에 놓는다.
4칸짜리 탑을 3번에 이동시키려면
: 3칸짜리 탑을 2번에 이동시킨후, 마지막 원판을 3번에 놓은 후, 3칸짜리를 4번에 놓는다.
...
N칸 짜리 탑을 3번에 이동시키려면,
 N-1탑을 2번에 이동시킨후 N번째 원판을 3번에 놓은후,
  2번에 있던 N-1번째 탑을 3번으로 이동시킨다.
*/
queue<pair<int, int>> qu;
int spair(int from, int to)
{ // from과 to를 제외한 자리
	return 6 - from - to;
}
void solve(int n, int from, int to) // n높이 탑을 from에서 to로 이동시킨다.
{
	if (n == 1)
	{
		qu.push(MP(from, to));
		return;
	}
	// n-1칸을 남은 칸에 올려놓은 후
	solve(n - 1, from, spair(from, to));
	//크기 n의 원판을 from에서 to에 올려놓은 후
	qu.push(MP(from, to));
	//다시 n-1 높이의 탑을 to로 올려놓는다.
	solve(n - 1, spair(from, to), to);
}
int main()
{
	FAST;
	int N;
	cin >> N;
	solve(N, 1, 3);
	cout << qu.size();
	while (!qu.empty())
	{
		pair<int, int> front = qu.front();
		cout << "\n";
		cout << front.first << " " << front.second;
		qu.pop();
	}
}
