#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (!a && !b)
			break;
		if (b % a == 0)
			cout << "factor\n";
		else if (a % b == 0)
			cout << "multiple\n";
		else
			cout << "neither\n";
	}
}

