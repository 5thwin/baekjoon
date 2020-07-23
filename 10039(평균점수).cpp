#include<cstdio>

using namespace std;

int main() {
	int score[5],sum=0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", score + i);
		if (score[i] < 40)
			score[i] = 40;
		sum += score[i];
	}
	
	printf("%d\n", sum / 5);
}