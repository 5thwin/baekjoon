#include <cstdio>

using namespace std;

int sum_10(int num)
{
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int sum_16(int num)
{
	int sum = 0;
	while (num)
	{
		sum += num % 16;
		num /= 16;
	}
	return sum;
}
int sum_12(int num)
{
	int sum = 0;
	while (num)
	{
		sum += num % 12;
		num /= 12;
	}
	return sum;
}
bool is_same3(int a, int b, int c)
{
	return (a == b && b == c);
}
int main()
{
	int s10, s12, s16;
	for (int num = 1000; num <= 9999; num++)
	{
		s10 = sum_10(num);
		s12 = sum_12(num);
		s16 = sum_16(num);
		if (is_same3(s10, s12, s16))
			printf("%d\n", num);
	}
}