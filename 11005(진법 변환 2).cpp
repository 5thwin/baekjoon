#include <iostream>
#include <vector>
using namespace std;

char digit2char(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}
void convert(int n, int b)
{
	int len = 0;
	vector<char> str;
	while (n)
	{
		str.push_back(digit2char(n % b));
		n /= b;
		len++;
	}
	while (len - 1 >= 0)
	{
		cout << str[--len];
	}
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, B;
	cin >> N >> B;
	convert(N, B);
}