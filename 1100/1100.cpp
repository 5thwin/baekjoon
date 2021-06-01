/*하얀 칸*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main() {
	string map[8];
	int ans = 0;

	for (int i = 0; i < 8; i++)
		cin >> map[i];
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if ((row + col) % 2 == 0 && map[row][col] == 'F')
				ans++;
		}
	}
	cout << ans;
}

