/*구간 합 구하기 2*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

using namespace std;

struct Leaf
{
	ll value, lazy;
	Leaf(){value = lazy = 0;}
};

vector<Leaf> tree;
vector<ll> input;
ll init(int node, int start, int end)
{
	if (start == end)
		return tree[node].value = input[start];
	int mid = (start + end)/2;
	return tree[node].value = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void propagate(int node, int start, int end)
{
	if (tree[node].lazy != 0)
	{
		tree[node].value += (end - start + 1) * tree[node].lazy;
		if (start != end)
		{
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
}
ll sum(int node, int start, int end,int left, int right)
{
	propagate(node, start, end);

	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node].value;
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update_range(int node, int start, int end, int left, int right, ll diff)
{
	propagate(node, start, end);

	if (right < start || end < left) return ;
	if (left <= start && end <= right){
		tree[node].value += (end - start + 1) * diff;
		if (start != end){
			tree[node * 2].lazy += diff;
			tree[node * 2 + 1].lazy += diff;
		}
		return ;
	}

	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, left, right, diff);
	update_range(node * 2 + 1, mid + 1, end, left, right, diff);
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}

void print_tree(int N)
{
	int step = 0, step_cnt;
	int index = 1;
	while (1)
	{
		step_cnt = pow(2, step);
		for (int i = 0; i < step_cnt; i++)
			cout << tree[index++].value << "  ";
		cout << "\n";
		if (step_cnt >= N)
			break;
		step++;
	}
}
int main() {
	FAST;
	int N, M, K;
	ll tmp;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}
	int h = (int)ceil(log2(N));
    int tree_size = (1 << (h+1));
	tree.resize(tree_size + 1);
	init(1, 0, N - 1);
	int a, b, c, d;
	while (M + K)
	{
		cin >> a;
		if (a == 1) //b번째부터 c번째까지 d를 더함
		{
			M--;
			cin >> b >> c >> d;
			b--,c--;
			update_range(1, 0, N - 1, b, c, d);

		}
		else //b번째부터 c번째 까지 구간합
		{
			K--;
			cin >> b >> c;
			b--, c--;
			cout << sum(1, 0, N - 1, b, c) << "\n";
		}
	}
}

