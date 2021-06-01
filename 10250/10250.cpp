/*ACM 호텔*/
#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main() {
	FAST;
	int T, H, W, N;
	int floor, number;
	cin >> T;
	while (T--)
	{
		cin >> H >> W >> N;
		floor = (N - 1) % H + 1;
		number = (N - 1) / H + 1;
		cout << floor;
		if (number < 10)
			cout << "0";
		cout << number << "\n";
	}

}

