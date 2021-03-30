#include <iostream>
#include <string>
#include <vector>
using namespace std;

char rotate(char c)
{
	if (c == '.')
		return '.';
	if (c == 'O')
		return 'O';
	if (c == '-')
		return '|';
	if (c == '|')
		return '-';
	if (c == '/')
		return '\\';
	if (c == '\\')
		return '/';
	if (c == '^')
		return '<';
	if (c == '<')
		return 'v';
	if (c == 'v')
		return '>';
	if (c == '>')
		return '^';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	vector<string> input;
	vector<vector<char>> output;
	cin >> N >> M;
	input.resize(N);
	output.resize(M, vector<char>(N));
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
		for (int j = 0; j < M; j++)
		{
			output[M - 1 - j][i] = rotate(input[i][j]);
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << output[i][j];
		cout << '\n';
	}
}