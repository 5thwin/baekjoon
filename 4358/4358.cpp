#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
typedef long long ll;
using namespace std;

int main() {
	FAST;
	string str;
	map<string, int> tremap;
	float total = 0;
	while (getline(cin, str))
	{
		total++;
		auto iter = tremap.find(str);
		if (iter == tremap.end()) //새로운 종 추가
		{
			tremap.insert(MP(str, 1));
		}
		else
		{
			iter->second++;
		}
	}
	for (auto iter = tremap.begin(); iter != tremap.end(); iter++)
	{
		string name = iter->first;
		float cnt = (float)(iter->second);
		cout << name << " ";
		float percent = (100 * cnt) / total;
		cout << fixed;
		cout.precision(4);
		cout << percent << "\n";

	}
}

