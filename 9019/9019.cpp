#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

int oper(int nbr, int ord) //ord - 0,1,2,3 : DSLR
{
	if (ord == 0) //D : 두 배
		return (2 * nbr) % 10000;
	if (ord == 1) //S : 1 빼기
		return (nbr + 9999) % 10000;
	if (ord == 2) // L : 왼쪽으로 회전
	{
		int tmp = nbr / 1000;
		return (nbr % 1000) * 10 + tmp;
	}
	if (ord == 3) // R 오른쪽으로 회전
	{
		int tmp = nbr % 10;
		return (nbr / 10) + (1000 * tmp);
	}
	else
		return -1;
}
string bfs(int start, int dest)
{
	bool visit[10000];
	int now, next;
	string str, nstr;
	char alpha[4] = {'D','S','L','R'};
	memset(visit, 0 ,sizeof(visit));
	queue< pair<int, string> > qu;
	qu.push(MP(start, ""));
	while (!qu.empty())
	{
		now = qu.front().first;
		str = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			next = oper(now, i);
			if (visit[next])
				continue;
			visit[next] = 1;
			nstr = str;
			nstr.push_back(alpha[i]); //nstr : str 뒤에 연산 알파벳을 붙임
			if (next == dest)
				return nstr;
			qu.push(MP(next, nstr));
		}
	}
	return "FAIL";
}
int main() {
	FAST;
	int T, A, B;
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		cout << bfs(A, B) << "\n";
	}
}

