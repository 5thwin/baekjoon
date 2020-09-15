/*메모리 초과*/
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define INF 987654321
typedef long long ll;

using namespace std;

vector <ll> input;
vector<pair<ll, int>> min_tree; //최솟값과 

int N;
pair<ll,int> init(vector<pair<ll,int>>& _tree, vector<ll>& _input, int node, int start, int end) {
	if (start == end) 
	{
	return _tree[node] = make_pair(_input[start], start); 
	}
	int mid = (start + end) / 2;
	pair<ll, int> left = init(_tree, _input, node * 2, start, mid);
	pair<ll, int> right = init(_tree, _input, node * 2 + 1, mid + 1, end);
	pair<ll, int> ret;
	if (left.first <= right.first) {
		ret = make_pair(left.first, left.second);
	}
	else
		ret = make_pair(right.first, right.second);

	return _tree[node] = ret;
}
pair<ll, int> minsearch(int left, int right, int node, int start, int end) {
	if (right < start || end < left) return make_pair( INF, 0 );
	if (left <= start && end <=right) {
		return min_tree[node];
	}
	int mid = (start + end)/2;
	pair<ll, int> left_c = minsearch(left,right,node*2,start,mid);
	pair<ll, int> right_c = minsearch(left, right, node*2+1, mid+1, end);
	pair<ll, int> ret;
	if (left_c.first <= right_c.first) {
		ret = make_pair(left_c.first, left_c.second);
	}
	else
		ret = make_pair(right_c.first, right_c.second);
	return ret;
}
ll max_area(int s, int e) {
	pair<ll, int > mins = minsearch(s,e,1,0, N-1);

	ll ret = (e - s + 1) * mins.first;
	if(s <= mins.second - 1 )
		ret = max(ret, max_area(s, mins.second - 1));
	if (mins.second+1 <= e)
		ret = max(ret, max_area(mins.second + 1, e));
	return ret;
}
int main() {
	
	while (1) {

		scanf("%d", &N);
		if (N == 0) break;
		input.clear();
		input.resize(N,INF);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &input[i]);
		}
		int h = ceil(log2(N)) + 1;
		min_tree.clear();
		min_tree.resize(pow(2, h) + 1, { INF,0 });
		init(min_tree, input, 1, 0, N - 1);
		int idx = 1;

		printf("%lld\n", max_area(0, N - 1));
	}
}
/*
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
*/