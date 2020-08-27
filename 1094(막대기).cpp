#include<cstdio>

using namespace std;

int main() {
	int N, H = 64, count = 0;
	scanf("%d", &N);
	while (N) {
		if (N >= H) {
			N -= H;
			count++;
		}
		H /= 2;
	}
	printf("%d", count);
}