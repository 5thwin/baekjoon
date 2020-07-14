#include<cstdio>

using namespace std;

int solve(int input) {
	int step = 0, m = 0;
	for (step = 0; step < 100000; step++) {
		m += step;
		if (input < 6 * m + 2) {
			return step + 1;
		}
	}
	return 0;
}
int main() {
	int N;
	scanf("%d", &N);
	printf("%d", solve(N));
}