#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int main() {
	FAST;
	int N, M;
	cin >> N >> M;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int i = 0, j = 0, sum = 0, ans = 0; //i부터 j번째까지 수열의 합을 sum에 저장
	while (1)
	{
		if (sum == M)
			ans++;
		if (sum <= M && j < N)
			sum += arr[j++];
		else if (sum > M)
			sum -= arr[i++];
		else //j가 마지막에 도달했고, sum이 M보다 작을때
			break;
	}
	cout << ans;
}

