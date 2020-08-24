//LIS처럼 풀기
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<pair<int, int>> arr;
int dp[100];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i,j, a, b, max_dpv, result;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());

	dp[0] = max_dpv = 1;
	for (i = 1; i < N; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (arr[j].second < arr[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		max_dpv = max(max_dpv, dp[i]);
	}
	result = N - max_dpv;
	cout << result;

}