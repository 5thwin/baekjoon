#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

set<int> intset;

int str2int(string str)
{
	int N = str.size();
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		ret = ret * 10 + (str[i] - '0');
	}
	return ret;
}
string arr[10];
int n, k;
void choose(int rec, string str, int bit)
{
	if (rec == 0)
	{
		int newint = str2int(str);
		intset.insert(newint);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (bit & (1 << i))
			continue;
		choose(rec - 1, str + arr[i], bit | (1 << i));
	}
}
int main() {
	FAST;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	choose(k, "", 0);
	cout << intset.size() << "\n";
}

