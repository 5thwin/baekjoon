#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
using namespace std;

int N, K;
string input[15];
int len[15], emod[15], tmod[51];
vector<vector<ll>> dp;
ll solve(int bit, int m) //dp(bit, m) : bit에 표시된 만큼 수를 포함시켰을 때, 나머지가 m이 나옴
{
	ll& ret = dp[bit][m];
	if (ret != -1)
		return ret;
	if (bit == (1 << N) - 1)
	{
		if (m) return ret = 0;
		return ret = 1;

	}
	ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (bit & (1 << i))
			continue;
		ret += solve(bit | (1 << i), (m * tmod[len[i]] + emod[i]) % K);
	}
	return (ret);
}
ll GCD(ll a, ll b) // a가 더 크다고 가정
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int main()
{
	FAST;
	/*입력받기*/
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> input[i];
	cin >> K;
	dp.resize(1 << N, vector<ll>(K, -1));
	/*10의 승수들에 대하여 나머지 구해놓기 -> tmod*/
	tmod[0] = 1 % K;
	for (int i = 1; i < 51; i++)
		tmod[i] = (tmod[i - 1] * 10) % K;

	/*각 입력된 자연수에 대해서 나머지 구해놓기 -> emod*/  
	for (int i = 0; i < N; i++)
	{
		len[i] = input[i].size();
		emod[i] = 0;
		int t = 0;
		for (int j = 0; j < len[i]; j++)
		{
			t *= 10; t += input[i][j] - '0'; t %= K;
		}
		emod[i] = t;
	}
	ll p = solve(0, 0), q = 1;
	if (p == 0)
		cout << "0/1\n";
	else
	{
		for (int i = 1; i <= N; i++)
			q *= (long long)i;
		ll gcd = GCD(q, p);
		cout << p / gcd << "/" << q / gcd << "\n";
	}
}