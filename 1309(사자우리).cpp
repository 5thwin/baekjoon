//�� �Ŀ��� 100000�� ���ؼ� ��������������� �������� �з���
#include<cstdio>
#include<cstring>
#define MOD 9901
using namespace std;

int dp[100001][3];
int solve(int N, int odr) {  //--> N��° �츮���� odr : 0-��ġ���� ���� 1-���ʿ� ��ġ 2-�����ʿ� ��ġ
	int& ref = dp[N][odr];
	if (ref != -1)
		return ref;
	if (N == 1) //ù��° -> ����, ������, ��ġX.
		return 1; //-> odr�� ���簣�� ���� �Ѱ��� ����� ��
	
	if (odr == 0)
		return ref = (solve(N - 1, 0) + solve(N - 1, 1) + solve(N - 1, 2))%MOD;
	if (odr == 1)
		return ref = (solve(N - 1, 0) + solve(N - 1, 2))%MOD;
	if (odr == 2)
		return ref = (solve(N - 1, 0) + solve(N - 1, 1))%MOD;
	return 0;
}
int main() {
	int N,ans;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	ans = (solve(N, 0) + solve(N, 1) + solve(N, 2))%MOD;
	printf("%d\n", ans);
}