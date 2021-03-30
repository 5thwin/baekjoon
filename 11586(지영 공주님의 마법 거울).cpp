#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, anger;
	string input;
	vector<vector<char>> mirror;
	cin >> N;
	mirror.resize(N, vector<char>(N));
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int s = 0; s < N; s++)
		{
			mirror[i][s] = input[s];
		}
	}
	cin >> anger;
	if (anger == 1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int s = 0; s < N; s++)
			{
				cout << mirror[i][s];
			}cout << "\n";
		}
	}
	else if (anger == 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int s = N - 1; s >= 0; --s)
			{
				cout << mirror[i][s];
			}cout << "\n";
		}
	}
	else
	{
		for (int i = N - 1; i >= 0; --i)
		{
			for (int s = 0; s < N; s++)
			{
				cout << mirror[i][s];
			}cout << "\n";
		}
	}

}