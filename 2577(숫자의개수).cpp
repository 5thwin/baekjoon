#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	int a, b, c, result, cnt[10];
	scanf("%d %d %d", &a, &b, &c);
	result = a * b * c;
	memset(cnt, 0, sizeof(cnt));

	while (result != 0) {
		cnt[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", cnt[i]);
	}
}