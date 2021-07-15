#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int dp[31][15001];//dp[num][weight] : num번 추까지 사용했을 때 weight 무게를 만들 수 있는지 여부
int N; //추의 개수
int w[31];
void solve(int num, int weight)
{
	if (num > N)
		return;
	int &ret = dp[num][weight];
	if (ret != -1)
		return;
	ret = 1;

	solve(num + 1, weight + w[num + 1]); //구슬과 반대 접시에 추를 올려놓음
	solve(num + 1, weight); //추를 올려놓지 않음
	solve(num + 1, abs(weight - w[num + 1])); //구슬과 같은 접시에 추를 올려놓음
}

int main() {
	FAST;
	cin >> N;
	w[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> w[i];
	int Q, marble;
	cin >> Q;
	memset(dp, -1, sizeof(dp));
	solve(0, 0);
	while (Q--)
	{
		cin >> marble;
		if (marble > 15000)
			cout << "N ";
		else if (dp[N][marble] == 1)
			cout << "Y ";
		else
			cout << "N ";
	}

}

