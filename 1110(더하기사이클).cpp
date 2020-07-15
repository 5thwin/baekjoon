#include<cstdio>

using namespace std;

int main() {
	int N, pre, next, length = 0;

	length = 0;
	scanf("%d", &N);
	pre = N;
	next = (pre % 10) * 10 + ((pre / 10) + (pre % 10)) % 10;
	while (1) {
		next = (pre % 10) * 10 + ((pre / 10) + (pre % 10)) % 10;
		length++;
		if (N == next)
			break;
		pre = next;
	}
	printf("%d\n", length);

}