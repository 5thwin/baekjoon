#include <iostream>

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, time = 0;
	bool lev = 0, multi = 0;
	char input[10];
	cin >> N >> input;
	for (int i = 0; i < N; i++)
	{
		if (time >= 2)
			break;
		if (input[i] == 'W')
			time++;
		if (input[i] == 'P')
		{
			lev = !lev;
			if (time == 1)
				multi = 1;
		}
	}
	if (time < 2)
		cout << "0\n";
	else if (multi)
		cout << "6\n";
	else if (lev)
		cout << "1\n";
	else
		cout << "5\n";
}