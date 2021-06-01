/*네 번째 점*/
#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int other(int p[])
{
	if (p[0] == p[1])
		return (p[2]);
	if (p[0] == p[2])
		return (p[1]);
	if (p[1] == p[2])
		return (p[0]);
	else
		return -1;
}

int main() {
	int x[3], y[3];
	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	cout << other(x) << " " << other(y);
}
