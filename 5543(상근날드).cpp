#include<cstdio>

using namespace std;

int min(int a, int b) {
	return (a < b) ? a : b;
}
int main() {
	int bugger, soda, sum = 0, mincost = 9999, i;
	for (i = 0; i < 3; i++) {
		scanf("%d", &bugger);
		mincost = min(mincost, bugger);
	}
	sum += mincost;
	mincost = 9999;
	for (i = 0; i < 2; i++) {
		scanf("%d", &soda);
		mincost = min(mincost, soda);
	}
	sum += mincost;
	printf("%d\n", sum - 50);
}