//에라토스테네스의 체
#include<cstdio>
#include<cstring>
#define MAX 123456
using namespace std;

bool prime[2*MAX+1];

int main() {
	int n;
	memset(prime, 1, sizeof(prime));
	prime[0] =prime[1]= false;
	for (int p = 2; p < MAX+1; p++) {
		if (prime[p] == false) continue;
		for (int i = 2; p * i <= 2 * MAX; i++) {
			prime[p * i] = false;
		}
	}

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		int sum = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			sum += prime[i];
		}
		printf("%d\n", sum);
	}
}