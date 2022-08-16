#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int main() {
	FAST;
	int N;
	ll M;
	cin >> N >> M;
	vector<ll> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int left = 0, right = 1;
	ll ans = 2000000001;
	while (1)
	{
		if (arr[right] - arr[left] >= M && right > left)
		{
			ans = min(ans, arr[right] - arr[left]);
			left++;
		}
		else
			right++;
		if (right == N)
			break;
	}
	cout << ans;
}
