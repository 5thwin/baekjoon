#include<cstdio>
using namespace std;

int K,a,b,temp;
int main() {
	scanf("%d", &K);
	a = 1, b = 0;
	for (int i = 1; i <= K; i++) {
		temp = b;
		b = a + b;
		a = temp;
	}
	printf("%d %d", a, b);
}