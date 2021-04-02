#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int len = input.size();
	for (int i = 0; i < len; i++)
	{
		cout << i << '\n';
	}
}