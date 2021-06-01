/*분수찾기*/
#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main() {
	FAST;
	int N;
	cin >> N;
	int x = 1, sum = 0;
	while (sum < N)
		sum += x++;
	x--;
	int y = N - (sum - x);
	if (x % 2) //홀수
		cout << x + 1 - y << '/' << y << "\n";
	else
		cout << y << "/" << x + 1 - y << "\n";
}

