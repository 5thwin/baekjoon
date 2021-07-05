#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int N, K; //물품수와 최대무게
int W[100], V[100]; //물건별 무게와 가치
int dp[100001][101]; //dp[c][n] : c무게만큼 더 넣을 수 있을때, n ~ N번 물건들 중 일부를 담아서 더 얻을 수 있는 최대 가치

int solve(int cap, int cur)
{

	if (cur == N) //더이상 담을 수 있는 물건이 없음 -> 더 얻을 가치가 없음
		return 0;
	int &ret = dp[cap][cur];
	if (ret != -1)
		return ret;
	//(1) cur번 물건을 담지 않은 경우
	ret = solve(cap, cur + 1); //남은 용량은 그대로
	//(2) cur번 물건을 담을 수 있을때는
	if (cap >= W[cur]) //물건을 담았을 때 얻을 수 있는 가치와 (1)의 결과 중 최대를 선택
		ret = max(ret, solve(cap - W[cur], cur + 1) + V[cur]);
	return ret;
}

int main() {
	FAST;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> W[i] >> V[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(K, 0);
}

