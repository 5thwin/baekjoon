#include <cstdio>

using namespace std;
/*2�� �������� 5�� ������ �� �����Ƿ� 5�ǰ����� ����*/
int main()
{
	int N, five = 0;
	scanf("%d", &N);
	for (int i = 5; i <= N; i *= 5)
	{
		five += (N / i);
	}
	printf("%d", five);
}