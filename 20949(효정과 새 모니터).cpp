#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int N, W, H;
vector<pair<int, int>> vec;
int main()
{
	FAST; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> W >> H;
		vec.push_back(MP(-W * W - H * H, i));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++)
	{
		cout << vec[i].second + 1 << "\n";
	}
}