#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int solve(int N, int M, vector<int> A, vector<int> B)
{
	int ans = 0, pa = 0, pb = 0;
	while (1)
	{
		if (A[pa] > B[pb] && pb < M) //먹을 수 있는 최대 크기까지 pb를 늘림
			pb++;
		else //먹을 수 없는 먹이가 등장
		{
			ans += pb;
			pa++;
			if (pa == N)
				break;
		}
	}
	return ans;
}
int main() {
	FAST;
	int T, N, M;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		vector<int> A(N), B(M);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int j = 0; j < M; j++)
			cin >> B[j];
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		cout << solve(N, M, A, B) << "\n";
	}
}

