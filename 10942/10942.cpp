#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;
int N, arr[2000], dp[2001][2001];
//dp[a][b] : a부터 b까지 수열이 펠린드롬인지 여부 (1, 0)
//펠린드롬 : 거꾸로 읽어도 똑같이 읽히는 수열
int solve(int s, int e)
{
	int &ret = dp[s][e];
	if (ret != -1)
		return ret;
	if (s == e) //한글자밖에 없을때
		return ret = 1;
	if (s + 1 == e) //두글자밖에 없을때, 두 글자가 같으면 펠린드롬
		return ret = (arr[s] == arr[e] ? 1 : 0);
	if (arr[s] == arr[e] && solve(s + 1, e - 1) == 1)
		return ret = 1; //s번째와 e번째가 같고, 그 둘을 제외한 나머지 수열이 펠린드롬일때
	return ret = 0;
}
int main() {
	FAST;
	int M, S, E;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> M;
	while (M--)
	{
		cin >> S >> E;
		cout << solve(S - 1, E - 1) << "\n";
	}
}

