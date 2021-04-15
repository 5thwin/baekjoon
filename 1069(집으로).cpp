#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF  987654321
#define MP make_pair
using namespace std;



int main()
{
	FAST;

	double X, Y;
	double D, T;
	double dist, time;
	int i_jump = 0;
	double jump;
	cin >> X >> Y >> D >> T;
	time = dist = (double)sqrt(X * X + Y * Y);
	/*처음부터 그냥 걸으면 time = dist*/
	i_jump = dist / D;
	jump = (double)i_jump;
	/*경우의수 1 : 점프로 지나친 후 걸어 돌아옴(일직선상으로 계속 점프만 뛰어서 도착하는 경우도 속함)*/
	time = min(T*(jump + 1) + (D*(jump + 1) - dist), time);
	/*경우의수 2 : 남은 거리를 2번에 점프*/
	time = min(T*(jump + 2), time);
	/*경우의 수 3 : 그냥 걸어서*/
	time = min(T * jump + (dist - (D * jump)), time);
	/*경우의 수 4 : jump를 한번 덜 하고 두번 점프로 거리를 뛰어감*/
	if (jump > 0)
		time = min((jump + 1) * T, time);
	cout << fixed;
	cout.precision(13);
	cout << time;
}
/*
3 4 3 1
*/