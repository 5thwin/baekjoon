#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

int main() {
	FAST;
	int N, M;
	cin >> N >> M;
	string domain, password;
	map<string, string> pwmap;
	for (int i = 0; i < N; i++)
	{
		cin >> domain >> password;
		pwmap.insert(MP(domain, password));
	}
	while (M--)
	{
		cin >> domain;
		cout << pwmap[domain] << "\n";
	}
}

