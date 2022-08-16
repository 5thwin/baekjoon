#include <iostream>
#include <vector>
#include <algorithm>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ABS(X) ((X) < 0 ? -(X) : (X))
typedef long long ll;
using namespace std;

int main() {
	FAST;
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int left = 0, right = N - 1, ans1, ans2, minabs = 2000000000;
	while (left < right)
	{
		if (ABS(arr[left] + arr[right]) < minabs)
		{
			minabs = ABS(arr[left] + arr[right]);
			ans1 = arr[left], ans2 = arr[right];
		}
		if (arr[left] + arr[right] > 0)
			right--;
		else if (arr[left] + arr[right] < 0)
			left++;
		else //정확히 0일때
			break;
	}
	cout << ans1 << " " << ans2 << "\n";
}

