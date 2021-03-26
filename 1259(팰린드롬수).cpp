#include <iostream>
#include <string.h>
using namespace std;


bool is_palindrome(string number)
{
	int len;

	len = number.size();
	for (int i = 0; i < len / 2; i++)
	{
		if (number[i] != number[len - 1 - i])
			return (0);
	}
	return (1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string input;

	while (1)
	{
		cin >> input;
		if (input == "0")
			break;
		if (is_palindrome(input))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}