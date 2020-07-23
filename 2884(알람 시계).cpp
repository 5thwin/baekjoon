#include<cstdio>
using namespace std;

int main() {
	int hour, min;
	scanf("%d %d", &hour, &min);
	min = min - 45;
	if (min < 0) {
		min += 60;
		hour--;
		if (hour < 0) {
			hour += 24;
		}
	}
	printf("%d %d\n", hour, min);

}