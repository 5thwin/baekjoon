#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int N, table[501][501];
vector<pair<int, pair<int,int>>> list;
int dir1[4] = { 0,0,1,-1 };
int dir2[4] = { -1,1,0,0 };
ll dp[501][501]; //-> i,j위치에서 시작했을 때, 가장 많이 갈 수 있는 길이
ll maxval = 0;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &table[i][j]);
			list.push_back( make_pair(table[i][j], make_pair(i, j)));
		}
	}
	memset(dp, 0, sizeof(dp));
	sort(list.rbegin(), list.rend());
	for (int i = 0; i < list.size(); i++) {
		pair<int,int> pos = list[i].second;
		int val = list[i].first;
		ll& ref = dp[pos.first][pos.second];
		ref = 1;
		for (int d = 0; d < 4; d++) {
			int next1 = pos.first + dir1[d];
			int next2 = pos.second + dir2[d];
			if (next1 <= 0 || next2 <= 0 || next1 > N || next2 > N)
				continue;
			if (table[next1][next2] <= val)
				continue;
			
			ref = max(ref, dp[next1][next2] + 1);
		}
		maxval = max(maxval, ref);
	}
	printf("%lld\n", maxval);
}