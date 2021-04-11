#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
using namespace std;

int N;
vector<pair<int, int>> usage;
priority_queue<pair<int, int>> min_end_qu;
priority_queue<int> min_emtpy_qu;
vector<int> person;
vector<int> ans;
int main()
{
	FAST;
	int p, q;
	cin >> N;
	usage.resize(N);
	person.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> p >> q;
		usage[i] = MP(p, q);
	}
	sort(usage.begin(), usage.end());
	int maxseat = 0;
	for (int i = 0; i < N; i++)
	{
		int start = usage[i].first;
		int end = usage[i].second;
		min_end_qu.push(MP(-end, i));
		int minend = -min_end_qu.top().first;
		int minnum = min_end_qu.top().second;
		if (start > minend)
		{
			while (start > minend && !min_end_qu.empty())
			{
				min_emtpy_qu.push(-person[minnum]);
				min_end_qu.pop();
				minend = -min_end_qu.top().first;
				minnum = min_end_qu.top().second;
			}
			person[i] = -min_emtpy_qu.top();
			ans[-min_emtpy_qu.top()]++;
			min_emtpy_qu.pop();
		}
		else if (!min_emtpy_qu.empty())
		{
			person[i] = -min_emtpy_qu.top();
			ans[-min_emtpy_qu.top()]++;
			min_emtpy_qu.pop();
		}
		else
		{
			ans.push_back(1);
			person[i] = maxseat;
			maxseat++;
		}
	}
	cout << maxseat << "\n";
	for (int i = 0; i < maxseat; i++)
		cout << ans[i] << " ";
}