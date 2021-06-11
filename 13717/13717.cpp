#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main() {
	FAST; int N;
	cin >> N;
	string name, max_name;
	int a, b, max_evo = -1, cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> name >> a >> b;
		int evo = 0;
		while (b / a)
		{
			evo += b / a;
			b = b % a + (b / a) * 2;
		}
		if (evo > max_evo)
		{
			max_evo = evo;
			max_name = name;
		}
		cnt += evo;
	}
	cout << cnt << "\n" << max_name;
}

