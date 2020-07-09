//1427(소트인사이드)
#include<stdio.h>
#include<algorithm>
using namespace std;

bool dec(int a, int b) {
	return a > b;
}

int main() {
	int input, sortarr[10];
	scanf("%d", &input);
	
	int n = 0;
	while (input) {
		sortarr[n++] = input % 10;
		input /= 10;
	}
	sort(sortarr, sortarr + n, dec);
	for (int i = 0; i < n; i++) {
		printf("%d", sortarr[i]);
	}
}