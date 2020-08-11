#include<iostream>
#include<cstring>
#include<string>
using namespace std;

#define MOD 1000000

string input;
int cache[5000];
int dp[5000];
int N;
int solve(int n) {
	int& ref = dp[n];
	if (ref != -1)
		return ref;
	if (cache[n] == 0)
		return ref = 0;

	if (n == N - 1) {
		return ref = 1;
	}
	if (n == N - 2) {
		if ((cache[n + 1] != 0)&& ((cache[n] == 1) || (cache[n] == 2 && cache[n + 1] < 7))) {
			return ref = 2;
		}
		if((cache[n + 1] != 0) || cache[n] <= 2)
			return ref = 1;
		return 0;
	}
	if ((cache[n + 1] != 0) && (cache[n] == 1 || (cache[n] == 2 && cache[n + 1] < 7))) //한자리도 될수 있고 두자리도 될수 있음
		return ref = (solve(n + 1) + solve(n + 2))%MOD;
	if ((cache[n + 1] == 0) && cache[n] <= 2) //두자리밖에 안됨
		return ref = solve(n + 2) % MOD;
	return ref = solve(n + 1) % MOD; //한자리밖에 안됨
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	memset(dp, -1, sizeof(dp));
	cin >> input;
	N = input.length();
	for (int i = 0; i < N; i++) {
		cache[i] = input[i] - '0';
	}
	cout << solve(0) << '\n';
	//for (int i = 0; i < N; i++) {
	//	cout << dp[i] << " ";
	//}
}