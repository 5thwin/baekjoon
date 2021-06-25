#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

// (1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)
int main() {
	FAST;
	int E, S, M;
	cin >> E >> S >> M;
	int end = 15 * 28 * 19;

	for (int a = 0; 15 * a + E <= end; a++)
	{
		int year = 15 * a + E;
		int b = year % 28;
		if (b == 0)
			b = 28;
		if (b != S)
			continue;
		b = year % 19;
		if (b == 0)
			b = 19;
		if (b != M)
			continue;
		cout << year << "\n";
		break;
	}
}

