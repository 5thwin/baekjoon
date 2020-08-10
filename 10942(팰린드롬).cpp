//팰린드롬 : 앞에서 읽어쓸 떄와 뒤에서 읽었을 떄 같은 수열
#include<cstdio>
#include<cstring>

using namespace std;

int cache[2000];
int dp[2000][2000];
int solve(int s, int e) {
	int& ref = dp[s][e];
	if (ref != -1)
		return ref;
	if (s == e) //한 개
		return ref = 1;
	if (e - s == 1) //두 개
	{
		if (cache[e] == cache[s])
			return ref = 1;
		return ref = 0;
	}
	if (solve(s + 1, e - 1) == 1 && cache[s] == cache[e])
		return ref = 1;
	return ref = 0;
}
int main() {
	int N, Q,S, E;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		scanf("%d", cache + i);
	}
	scanf("%d" ,&Q);
	for (int q = 0; q < Q; q++) {
		scanf("%d %d", &S, &E);
		S--, E--;
		printf("%d\n", solve(S, E));
	}

}