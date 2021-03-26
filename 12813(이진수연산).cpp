#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string A, B;
	int len;
	cin >> A >> B;
	len = A.size();
	// A&B
	for (int i = 0; i < len; i++)
	{
		if (A[i] == '1' && B[i] == '1')
			cout << '1';
		else
			cout << '0';
	}
	cout << '\n';
	// A | B
	for (int i = 0; i < len; i++)
	{
		if (A[i] == '1' || B[i] == '1')
			cout << '1';
		else
			cout << '0';
	}
	cout << '\n';
	// A ^ B
	for (int i = 0; i < len; i++)
	{
		if (A[i] != B[i])
			cout << '1';
		else
			cout << '0';
	}
	cout << '\n';
	// ~A
	for (int i = 0; i < len; i++)
	{
		if (A[i] == '1')
			cout << '0';
		else
			cout << '1';
	}
	cout << '\n';
	// ~B
	for (int i = 0; i < len; i++)
	{
		if (B[i] == '1')
			cout << '0';
		else
			cout << '1';
	}
	cout << '\n';
	
}