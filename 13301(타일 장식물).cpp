#include<cstdio>

typedef long long ll;
using namespace std;

ll H, V; //���� ����
int main() {
	int N;
	scanf("%d", &N);
	H = 0,V = 1;
	for (int i = 1; i <= N; i++) {
		if (i % 2)//Ȧ����°
			H += V;
		else
			V += H;
	}
	ll ans = 2*(H + V);
	printf("%lld", ans);
}