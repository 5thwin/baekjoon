#include <stdio.h>
#define MAXDAY 14

using namespace std;

int three_days(int *day, int i)
{
	if (i < 3)
		return (0); //3��ġ ����� �����Ƿ� �ƹ� �ൿ ���� ����
	if (day[i] > day[i - 1] && day[i - 1] > day[i - 2] && day[i - 2] > day[i - 3])
		return (1);  //3�� ���� ���� -> �Ǹ�
	if (day[i] < day[i - 1] && day[i - 1] < day[i - 2] && day[i - 2] < day[i - 3])
		return (-1);  //3�� ���� �϶� -> ����
	return (0);
}
int main()
{
	int day[MAXDAY];
	int cash1, cash2, stock1, stock2;
	int i;

	scanf("%d", &cash1);
	cash2 = cash1;
	stock1 = stock2 = 0;
	for (i = 0; i < MAXDAY; i++)
		scanf("%d", &day[i]);
	for (i = 0; i < MAXDAY - 1; i++)
	{
		/*��������*/
		if (cash1 >= day[i]) 
		{
			stock1 += cash1 / day[i];
			cash1 %= day[i];
		}
		/*��������*/
		if (three_days(day, i) == 1)
		{
			cash2 += stock2 * day[i];
			stock2 = 0;
		}
		else if (three_days(day, i) == -1 && cash2 >= day[i])
		{
			stock2 += cash2 / day[i];
			cash2 %= day[i];
		}
	}
	/*��������*/
	cash1 += stock1 * day[MAXDAY - 1];
	cash2 += stock2 * day[MAXDAY - 1];
	if (cash1 > cash2)
		printf("BNP\n");
	else if (cash2 > cash1)
		printf("TIMING\n");
	else
		printf("SAMESAME\n");
}