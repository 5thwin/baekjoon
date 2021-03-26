#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MP make_pair
using namespace std;

int main()
{
	int T, N, M, input, nowim, nownum, idx, ord = 0;
	queue<pair<int, int>> prtqu;
	vector<int> important;
	scanf("%d", &T);
	while (T--)
	{
		idx = ord = 0;
		while (!prtqu.empty())
			prtqu.pop();
		important.clear();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &input);
			prtqu.push(MP(input, i));
			important.push_back(input);
		}
		sort(important.begin(), important.end(), greater<int>());
		while (!prtqu.empty() && idx < N)
		{
			nowim = prtqu.front().first;
			nownum = prtqu.front().second;
			prtqu.pop();
			if (nowim == important[idx]) //Ãâ·Â
			{
				idx++;
				ord++;
			}
			else
			{
				prtqu.push(MP(nowim, nownum));
				continue;
			}
			if (nownum == M)
				break;
		}
		printf("%d\n", ord);
	}
}