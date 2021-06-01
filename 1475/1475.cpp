/*방 번호*/
#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main() {
	FAST;
	char input[8];
	int cnt[10] = {0, };
	int ans = 0;

	cin >> input;
	for (int i = 0; i < 8 && input[i] != '\0'; i++)
		cnt[input[i] - '0']++;
	for (int i = 0; i < 9; i++)
	{
		if (i == 6)
			ans = max(ans, (cnt[i] + cnt[9] + 1) / 2);
		else
			ans = max(ans, cnt[i]);
	}
	cout << ans;
}

