#include <cstdio>

using namespace std;

/*���װ�� ���� ����ص���*/
int combi(int n, int r)
{
	if (n == 0)
		return (0);
	if (r == 0 || n == r)
		return (1);
	return combi(n - 1, r - 1) + combi(n - 1, r);
}

int main()
{
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d", combi(n, r));
}