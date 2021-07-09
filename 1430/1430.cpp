#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

double x[101], y[101];
double R, D; //사정거리, 초기에너지
double distant(double x, double y, double _x, double _y)
{
	return sqrt(pow(abs(x - _x), 2) + pow(abs(y - _y), 2));
}

double bfs(double sx, double sy, int N)
{
	vector<bool> visit(N + 1, 0);
	double ret;
	queue< pair<int, int> > qu; //탑 번호와 몇번을 거쳐 공격해야하는지
	qu.push(MP(0, 0));
	visit[0] = 1;
	while (!qu.empty())
	{
		int idx = qu.front().first;
		int step = qu.front().second;
		qu.pop();
		double cx = x[idx];
		double cy = y[idx];

		if (idx != 0)
			ret += D/pow(2, step - 1);
		for (int i = 1; i <= N; i++)
		{
			double nx = x[i];
			double ny = y[i];
			double dist = distant(cx, cy, nx, ny);

			if (dist > R)
				continue;
			if (visit[i])
				continue;
			visit[i] =  1;
			qu.push(MP(i, step + 1));
		}
	}
	return ret;
}
int main() {
	FAST;
	int N;
	cin >> N >> R >> D >> x[0] >> y[0];
	for (int i = 1; i <= N; i++)
		cin >> x[i] >> y[i];
	cout << fixed;
	cout.precision(2);
	cout << bfs(x[0], y[0], N);
}

