#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FAST ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
int NMAX;
//1 < n <= 2^31
int ft_range(unsigned int n)
{
	if (n == 1)
		return (1);
	unsigned int i = 1, a, b, c;

	while (i < NMAX)
	{
		a = i* i;
		b = i * (i + 1);
		c = (i + 1) * (i + 1);
		if (a < n && n <= b)
			return (i * 2);
		if (b < n && n <= c)
			return (i * 2 + 1);
		i++;
	}
}
int main()
{
	NMAX = pow(2, 31);
	unsigned int T, a, b, n;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		n = b - a;
		cout << ft_range(n) << "\n";
	}
}