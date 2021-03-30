#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, num, numsq, minsqu = -1, sum = 0;;
	cin >> N >> M;
	num = sqrt(N);
	while ((numsq = num * num) <= M)
	{
		num++;
		if (numsq < N)
			continue;
		if (minsqu == -1)
			minsqu = numsq;
		sum += numsq;
	}
	if (minsqu == -1)
		cout << "-1\n";
	else
		cout << sum << "\n" << minsqu;
}