#include <cstdio>

using namespace std;

int rate(long long X, long long Y, long long W)
{
	return ((Y + W) * 100) / (X + W);
}
int main()
{
	long long X, Y, Z, W;
	long long left, right, mid;
	scanf("%lld %lld", &X, &Y);
	Z = (Y * 100) / X;
	left = 0;
	right = X;
	W = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (rate(X, Y, mid) > Z)
		{
			W = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	printf("%lld", W);
	
}