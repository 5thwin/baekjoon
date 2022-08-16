#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
typedef long long ll;
using namespace std;

int main() {
	FAST;
	int N, K;
	cin >> N >> K;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int s = 0, e = 0, lion = (arr[0] == 1 ? 1 : 0), minset = INF; //라이언 인형의 초기값은 첫번째 인형이 라이언이면 1, 아니면 0
	while (1)
	{
		if (lion == K)
			minset = min(e - s + 1, minset);
		if (s == N - 1) //모든 범위를 다 탐색함
			break;
		if (lion < K && e < N - 1) //s~e범위 내에 라이언 인형이 K개 보다 적거나 같으면
			lion += (arr[++e] == 1 ? 1 : 0);
		else
			lion -= (arr[s++] == 1 ? 1 : 0);
	}
	cout << (minset == INF ? -1 : minset);
}

