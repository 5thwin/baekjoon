#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
struct Cmp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
int main()
{
	FAST;
	int X;
	cin >> N;
	priority_queue<int, vector<int>, Cmp> minqu;
	while (N--)
	{
		cin >> X;
		if (X != 0)
			minqu.push(X);
		else
		{
			if (!minqu.empty()) {
				cout << minqu.top() << "\n";
				minqu.pop();
			}
			else
				cout << "0" << "\n";
		}
	}
}