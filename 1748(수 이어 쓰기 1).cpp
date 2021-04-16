#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
using namespace std;

int N;

int main()
{
	FAST; cin >> N;
	if (N < 10) {
		cout << N;
		return 0;
	}
	long long ans = 0;
	long long digit = 1; // 자릿수
	/*N 이 몇자리 수인지 파악*/
	while (1)
	{
		if (N < pow(10, digit))
			break;
		ans += (pow(10, digit) - pow(10, digit - 1)) * digit; //개수 * 자릿수 
		digit++;
	}
	ans += digit * (N - pow(10, digit - 1) + 1);
	cout << ans ;
}