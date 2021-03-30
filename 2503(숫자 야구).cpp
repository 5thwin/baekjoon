#include <cstdio>
#include <cstring>
using namespace std;

int ft_strik(int a, int b)
{
	int ret = 0;
	while (a)
	{
		if (a % 10 == b % 10)
			ret++;
		a /= 10;
		b /= 10;
	}
	return ret;
}
int ft_ball(int a, int b)
{
	int ret = 0, tmpb;
	for (int i = 0; i < 3; i++)
	{
		tmpb = b;
		for (int j = 0; j < 3; j++)
		{
			if (i != j && a % 10 == tmpb % 10)
				ret++;
			tmpb /= 10;
		}
		a /= 10;
	}
	return ret;
}
bool is_dup(int num)
{
	int digit[3];
	for (int i = 0; i < 3; i++)
	{
		digit[i] = num % 10;
		num /= 10;
	}
	return (digit[0] == digit[1] || digit[1] == digit[2] || digit[2] == digit[0]);
}
bool in_zero(int num)
{
	while (num)
	{
		if (num % 10 == 0)
			return (1);
		num /= 10;
	}
	return (0);
}
int main()
{
	bool is_ans[1000];
	int N, question, strik, ball, anscnt = 0;
	for (int i = 0; i <= 999; i++)
	{
		if (i <= 101)
			is_ans[i] = 0;
		else if (is_dup(i))
			is_ans[i] = 0;
		else if (in_zero(i))
			is_ans[i] = 0;
		else
			is_ans[i] = 1;
	}
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d %d %d", &question, &strik, &ball);
		for (int num = 102; num <= 999; num++)
		{
			if (is_ans[num] == 0)
				continue;
			if (ball == ft_ball(num, question) && strik == ft_strik(num, question))
				continue;
			is_ans[num] = 0;
		}
	}
	for (int i = 0; i <= 999; i++)
	{
		if (is_ans[i])
			anscnt++;
	}
	printf("%d\n", anscnt);
}