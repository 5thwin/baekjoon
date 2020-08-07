#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int dp_max[2][3];
int dp_min[2][3];
int table[100000][3];

int main() {
	scanf("%d", &N);
	memset(dp_max, -1, sizeof(dp_max));
	memset(dp_min, -1, sizeof(dp_min));
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &table[i][0], &table[i][1], &table[i][2]);
	}
	dp_max[0][0] = table[N-1][0]; dp_max[0][1] = table[N-1][1]; dp_max[0][2] = table[N-1][2];
	dp_min[0][0] = table[N-1][0]; dp_min[0][1] = table[N-1][1]; dp_min[0][2] = table[N-1][2];
	for (int i = 1; i < N; i++) {
		dp_max[i % 2][0] = table[N - 1 - i][0] + max(dp_max[(i + 1) % 2][0], dp_max[(i + 1) % 2][1]);
		dp_max[i % 2][1] = table[N - 1 - i][1] + max(max(dp_max[(i + 1) % 2][0], dp_max[(i + 1) % 2][1]),dp_max[(i+1)%2][2]);
		dp_max[i % 2][2] = table[N - 1 - i][2] + max(dp_max[(i + 1) % 2][1], dp_max[(i + 1) % 2][2]);

		dp_min[i % 2][0] = table[N - 1 - i][0] + min(dp_min[(i + 1) % 2][0], dp_min[(i + 1) % 2][1]);
		dp_min[i % 2][1] = table[N - 1 - i][1] + min(min(dp_min[(i + 1) % 2][0], dp_min[(i + 1) % 2][1]), dp_min[(i + 1) % 2][2]);
		dp_min[i % 2][2] = table[N - 1 - i][2] + min(dp_min[(i + 1) % 2][1], dp_min[(i + 1) % 2][2]);
	}
	int maxval = 0,  minval = 987654321;
	for (int i = 0; i < 3; i++) {
		maxval = max(maxval, dp_max[(N - 1) % 2][i]);
		minval = min(minval, dp_min[(N - 1) % 2][i]);
	}
	printf("%d %d\n", maxval, minval);
}