#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
using namespace std;

int dp[101][101][101];
int a, b, c;
int w(int a, int b, int c)
{
	int& ret = dp[a + 50][b + 50][c + 50];
	if (ret != 0)
		return ret;
	if (a <= 0 || b <= 0 || c <= 0)
		return ret = 1;
	if (a > 20 || b > 20 || c > 20)
		return ret = w(20, 20, 20);
	if (a < b && b < c)
		return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
	FAST;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
	return (0);
}