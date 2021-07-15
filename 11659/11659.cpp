#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int main() {
	FAST;
	int N, Q, a, b, arr[100001], sum[100001];
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	arr[0] = sum[0] = 0;
	for (int i = 1; i <= N; i++)
		sum[i] = sum[i - 1] + arr[i];
	while (Q--)
	{
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
}

