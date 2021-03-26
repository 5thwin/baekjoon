#include <cstdio>
#include <vector>
#define MP make_pair

using namespace std;

int N, W;
int main()
{
	vector<pair<int, int>> cows;
	int a, b;
	scanf("%d %d", &N, &W);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		cows.push_back(MP(a, b));
	}
}