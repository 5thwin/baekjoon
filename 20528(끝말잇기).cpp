#include<iostream>
#include<string.h>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, ans = 1;
	char alpha;
	string input;
	cin >> N;
	N--;
	cin >> input;
	alpha = input[0];
	while (N--)
	{
		cin >> input;
		if (alpha != input[0])
			ans = 0;
	}
	cout << ans;
}