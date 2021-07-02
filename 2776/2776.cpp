#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int main() {
	FAST;
	int T, N, M, input;
	cin >> T;
	while (T--)
	{
		set<int> intset;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> input;
			intset.insert(input);
		}
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> input;
			auto iter = intset.find(input);
			if (iter == intset.end())
				cout << "0\n";
			else
				cout << "1\n";
		}
	}
}

