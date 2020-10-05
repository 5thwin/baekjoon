#include<cstdio>

typedef long long ll;
using namespace std;

ll H, V; //가로 세로
int main() {
	int N;
	scanf("%d", &N);
	H = 0,V = 1;
	for (int i = 1; i <= N; i++) {
		if (i % 2)//홀수번째
			H += V;
		else
			V += H;
	}
	ll ans = 2*(H + V);
	printf("%lld", ans);
}