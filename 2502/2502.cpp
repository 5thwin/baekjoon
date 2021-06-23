#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

pair<int, int> dp[31]; //n일째 되는 날 첫번째 날의 떡 개수와 두번째날 떡 개수의 계수
int D, K;
pair<int, int> solve(int n)
{
	if (dp[n].first != -1)
		return dp[n];
	if (n == 1)
		return dp[n] = MP(1, 0);
	if (n == 2)
		return dp[n] = MP(0, 1);
	pair<int, int> a = solve(n - 1);
	pair<int, int> b = solve(n - 2);
	return dp[n] = MP(a.first + b.first, a.second + b.second);
}
pair<int, int> retAns(int a, int b, int K)
{
	//ai * bj = K 가 참이되는 i, j찾기
	for (int i = 1; i < K; i++)
	{
		for (int j = i; j < K; j++)
		{
			if (a * i +  b * j == K)
				return MP(i, j);
			if (a * i + b * j > K)
				break;
		}
	}
	return MP(-1, -1);
}
int main() {
	FAST;
	cin >> D >> K;
	for (int i = 0; i <= D; i++)
		dp[i] = MP(-1, -1);
	pair<int, int> p = solve(D);
	pair<int, int> ans = retAns(p.first, p.second, K);
	cout << ans.first << "\n" << ans.second << "\n";
}

