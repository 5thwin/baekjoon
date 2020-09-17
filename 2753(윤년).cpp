#include<cstdio>

using namespace std;

int main() {
	int N;
	bool flag = 0;
	scanf("%d", &N);
	if (N % 4 == 0) {
		flag = 1;
		if (N % 100 == 0) {
			flag = 0;
			if (N % 400 == 0) {
				flag = 1;
			}
		}
	}
	printf("%d\n", flag);
}