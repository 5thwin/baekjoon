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
	/*ó������ �׳� ������ time = dist*/
	i_jump = dist / D;
	jump = (double)i_jump;
	/*����Ǽ� 1 : ������ ����ģ �� �ɾ� ���ƿ�(������������ ��� ������ �پ �����ϴ� ��쵵 ����)*/
	time = min(T*(jump + 1) + (D*(jump + 1) - dist), time);
	/*����Ǽ� 2 : ���� �Ÿ��� 2���� ����*/
	time = min(T*(jump + 2), time);
	/*����� �� 3 : �׳� �ɾ*/
	time = min(T * jump + (dist - (D * jump)), time);
	/*����� �� 4 : jump�� �ѹ� �� �ϰ� �ι� ������ �Ÿ��� �پ*/
	if (jump > 0)
		time = min((jump + 1) * T, time);
	cout << fixed;
	cout.precision(13);
	cout << time;
}
/*
3 4 3 1
*/