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

bool hasGenerator[11107];
int calcSelfNumber(int n)
{
	int ret = n;
	while (n)
	{
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	FAST;
	int n = 1;
	while (n < 10000)
	{
		int selfNum = calcSelfNumber(n);
		if (selfNum >= 11106)
			break;
		hasGenerator[selfNum] = true;
		n++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (!hasGenerator[i])
			cout << i << "\n";
	}
}
