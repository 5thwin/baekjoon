#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 2147483640
typedef long long ll;
using namespace std;

int N;
vector<int> T, P, dp;
//dp[x] = x일부터 N일까지 얻을 수 있는 최대 비용
int solve(int x)
{
	if (x >= N) //퇴사일 이후일 경우 0
		return 0;
	int &ret = dp[x];
	if (x + T[x] > N) //상담이 끝나는 날이 퇴사 이후일 경우 상담할수없음
		return ret = solve(x + 1);
	if (ret != -1)
		return ret;
	return ret = max(P[x] + solve(x + T[x]), solve(x + 1));
}
int main() {
	FAST;
	int ti, pi;
	cin >> N;
	dp.resize(N, -1);
	for (int i = 0; i < N; i++)
	{
		cin >> ti >> pi;
		T.push_back(ti);
		P.push_back(pi);
	}
	cout << solve(0);
}

