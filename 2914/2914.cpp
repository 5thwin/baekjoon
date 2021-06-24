#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int main() {
	FAST;
	int A, I;
	cin >> A >> I;
	int ans = A * I;
	int left = 0, right = ans;
	while (left < right)
	{
		double mid = (left + right) / 2;
		int avg = (int)(ceil(mid/A));
		if (avg == I)
		{
			ans = mid;
			right = mid;
		}
		else //ceil(mid / A) < I
		{
			left = mid + 1;
		}
	}
	cout << ans;
}

