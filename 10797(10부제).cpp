#include<cstdio>

using namespace std;

int main() {
	int d, c,count = 0;
	scanf("%d", &d);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &c);
		if(d == c) count++;
	}
	printf("%d\n", count);
	
}