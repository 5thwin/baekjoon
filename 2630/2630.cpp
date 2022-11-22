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

int N;
int field[128][128];
int blue = 0;
int white = 0;
void insertInput();
pair<int, int> addFourPair(pair<int, int> *arr)
{
	int first = 0, second = 0;
	for (int i = 0; i < 4; i++)
	{
		first += arr[i].first;
		second += arr[i].second;
	}
	return MP(first, second);
}
//길이가 n/2인 영역 4개(1,2,3,4분면)가 모두 같은 색이라면 길이가 n인 영역은 같은 색이다.
//왼쪽 끝 죄표가 (y,x)이고 길이가 l인 영역에서 모두 같은 색으로 칠해져있는지 확인하는 함수
// 1,2,3,4분면을 탐색 후, 하얀영역과 파란 영역을 짝으로 리턴해준다. 만약 모두 같은 색으로 나왔다면 그 색으로 1을 리턴해준다.
pair<int, int> solve(int y, int x, int l)
{
	if (l == 0) //한칸을 확인하는 경우
	{
		if (field[y][x] == 0)
			return MP(1, 0);
		return MP(0, 1);
	}
	pair<int, int> area[4];
	area[0] = solve(y, x + (l / 2), l / 2);
	area[1] = solve(y + (l / 2), x + (l / 2), l / 2);
	area[2] = solve(y + (l / 2), x, l / 2);
	area[3] = solve(y, x, l / 2);
	pair<int, int> result = addFourPair(area);
	//만약 파란색, 혹은 하얀색영역의 개수가 0이라면 이 영역은 한개로 퉁칩니다.
	if (result.first == 0)
		return MP(0, 1);
	if (result.second == 0)
		return MP(1, 0);
	return result;
}

int main()
{
	FAST;
	// freopen("../../input.txt", "r", stdin);
	insertInput();
	pair<int, int> result = solve(0, 0, N);
	cout << result.first << "\n"
		 << result.second;
}
void insertInput()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> field[i][j];
		}
	}
}
