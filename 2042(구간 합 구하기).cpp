#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;


vector<ll> input, tree;

ll init(vector<ll>& _tree, vector<ll>& _input, ll node, ll start, ll end)
{
	if (start == end)
		return _tree[node] = _input[start];
	int mid = (start + end) / 2;
	return _tree[node] = init(_tree, _input, node * 2, start, mid) + init(_tree, _input, node * 2 + 1, mid + 1, end);
}
ll update(int pos, int c, int node, int start, int end) {
	if (pos < start || end < pos)return tree[node];
	if (start == end) return tree[node] = c;
	ll mid = (start + end) / 2;
	return tree[node] = update(pos, c, node * 2, start, mid)+  update(pos, c, node * 2 + 1, mid + 1, end);
}
ll sum(int left, int right, int node, int start, int end) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	ll mid =(start + end) / 2;
	return sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid + 1, end);
}

int main() {
	ll N, M, K, in;
	int a,b,c;
	scanf("%lld %lld %lld", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &in);
		input.push_back(in);
	}
	ll h = ceil(log2(N)) + 1;
	tree.resize(pow(2, h));
	init(tree, input, 1, 0, N-1);

	//int idx = 1;
	//for (int i = 0; i < h; i++) {
	//	for (int j = 1; j <= pow(2, i);j++ ) {
	//		printf("%lld ", tree[idx++]);
	//	}printf("\n");
	//}

	while (M != 0 || K != 0) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)
		{
			M--;
			b--;
			update(b, c, 1, 0, N - 1);
		}
		else if (a == 2)
		{
			K--;
			b--; c--;

			printf("%lld\n",sum(b, c, 1, 0, N - 1));
		}

	}

}