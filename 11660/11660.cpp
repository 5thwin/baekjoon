#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
using namespace std;

int arr[1025][1025], sum[1025][1025];
int main() {
	FAST;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			sum[i][j] = arr[i][j] + sum[i][j-1] + sum[i - 1][j] - sum[i - 1][j - 1];
	}

	/*(x1,y1) 부터 (x2,y2)까지 합*/
	int x1,y1,x2,y2;
	while(M--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - (sum[x2][y1 - 1] + sum[x1 - 1][y2]) + sum[x1-1][y1-1] << "\n";
	}
}

