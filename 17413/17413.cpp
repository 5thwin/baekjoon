#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main() {
	FAST;
	string input;
	stack<char> st;
	getline(cin, input);
	int N = input.size();
	for (int i = 0; i < N; i++)
	{
		char cur = input[i];
		if (cur == '<')
		{
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			while (input[i] != '>')
				cout << input[i++];
			cout << input[i];
			continue;
		}
		else if (cur != ' ')
			st.push(cur);
		else if (cur == ' ')
		{
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			cout << cur;
		}
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

