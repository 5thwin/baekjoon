#include<cstdio>
using namespace std;

int main() {
	int tot, cost;
	scanf("%d", &tot);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &cost);
		tot -= cost;
	}
	printf("%d\n", tot);
}