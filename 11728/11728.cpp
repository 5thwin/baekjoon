#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int main() {
	FAST;
	vector<int> A,B;
	int N, M;
	cin >> N >> M;
	A.resize(N);
	B.resize(M);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++)
		cin >> B[i];
	int pa = 0, pb = 0;
	while (pa < N && pb < M)
	{
		if (A[pa]  < B[pb])
			cout << A[pa++] << " ";
		else
			cout << B[pb++] << " ";
	}
	while (pa < N)
		cout << A[pa++] << " ";
	while (pb < M)
		cout << B[pb++] << " ";

}

