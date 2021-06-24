#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

int ft_stoi(string str)
{
	int len = str.size();
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret = ret * 10 + (int)(str[i] - '0');
	}
	return ret;
}
int main() {
	FAST;
	int N, M;
	string name;
	map< string, int > poket;
	string dic[100001];
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> name;
		poket.insert(MP(name, i));
		dic[i] = name;
	}
	string input;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		if (input[0] >= '1' && input[0] <= '9')
		{
			cout << dic[ft_stoi(input)] << "\n";
		}
		else
		{
			cout << poket[input] << "\n";
		}
	}
}

