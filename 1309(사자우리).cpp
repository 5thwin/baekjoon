//내 컴에서 100000에 대해서 계산하지못했지만 정답으로 분류됨
#include<cstdio>
#include<cstring>
#define MOD 9901
using namespace std;

int dp[100001][3];
int solve(int N, int odr) {  //--> N번째 우리에서 odr : 0-배치하지 않음 1-왼쪽에 배치 2-오른쪽에 배치
	int& ref = dp[N][odr];
	if (ref != -1)
		return ref;
	if (N == 1) //첫번째 -> 왼쪽, 오른쪽, 배치X.
		return 1; //-> odr가 뭐든간에 각각 한가지 경우의 수
	
	if (odr == 0)
		return ref = (solve(N - 1, 0) + solve(N - 1, 1) + solve(N - 1, 2))%MOD;
	if (odr == 1)
		return ref = (solve(N - 1, 0) + solve(N - 1, 2))%MOD;
	if (odr == 2)
		return ref = (solve(N - 1, 0) + solve(N - 1, 1))%MOD;
	return 0;
}
int main() {
	int N,ans;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	ans = (solve(N, 0) + solve(N, 1) + solve(N, 2))%MOD;
	printf("%d\n", ans);
}