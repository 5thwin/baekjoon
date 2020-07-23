//피보나치처럼 풀기
#include<cstdio>

#define MOD 10007

using namespace std;

int a = 1, b = 3;
int pow(int x, int y) {
	int ret = 1;
	for (int i = 0; i < y; i++) {
		ret = (ret * x) % MOD;
	}
	return ret;
}
int solve(int N) {
	int ret;
	if (N == 1)
		return a;
	if (N == 2)
		return b;
	//홀수
	if (N % 2) 
	{
		//N = 3일때 2a + b = 5
		int m = (N- 3)/2;
		ret = 5;
		for (int i = 0; i < m; i++) {
			ret += (pow(4,(i+1))  * (a + b))%MOD;
			ret %= MOD;
		}
		return ret;
	}
	//짝수
	else 
	{
		//N = 4일떄 2a + 3b = 11
		int m = (N - 4) / 2;
		ret = 11;
		for (int i = 0; i < m; i++) {
			ret += (2*pow(4, (i + 1)) * (a + b) )% MOD;
			ret %= MOD;
		}
		return ret;
	}
}
int main() {
	int N;
	
	scanf("%d", &N);
	printf("%d\n",solve(N));
}