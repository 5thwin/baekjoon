#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;


pair<int, int> point[100];
int N;
bool square_check(int minx, int maxx, int miny, int maxy)
{
	for (int i = 0; i < N; i++)
	{
		int x = point[i].first;
		int y = point[i].second;
		if (x != maxx && x != minx && y != maxy && y != miny)
			return (0);
	}
	return (1);
}
int main() {
	FAST;

	cin >> N;
	int a, b;
	int minx = 1001, miny = 1001;
	int maxx = -1001, maxy = -1001;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		minx = min(minx, a);
		maxx = max(maxx, a);
		miny = min(miny, b);
		maxy = max(maxy, b);
		point[i].first = a;
		point[i].second = b;
	}
	int ans = max(maxx - minx, maxy - miny);
	if (maxx - minx >= maxy - miny)
	{
		if (square_check(minx, maxx, miny, miny + ans))
		;
		else if(square_check(minx, maxx, maxy - ans, maxy))
		;
		else
			ans = -1;
	}
	else
	{
		if (square_check(minx, minx + ans, miny, maxy))
		;
		else if(square_check(maxx - ans, maxx, miny, maxy))
		;
		else
			ans = -1;
	}
	cout << ans;
}

