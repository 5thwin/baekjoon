#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, R;
	char str[21];
	cin >> T;
	while (T--)
	{
		cin >> R >> str;
		for (int i = 0; str[i] != 0; i++)
		{
			for (int j = 0; j < R; j++)
			{
				cout << str[i];
			}
		}
		cout << '\n';
	}
	
}