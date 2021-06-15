/*스위치*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
using namespace std;

struct Leaf
{
	/* data */
	int value, lazy;
	Leaf(){value = lazy = 0;}
};
vector<Leaf> tree;
void propatage(int node, int start, int end)
{
	if (tree[node].lazy != 0)
	{
		tree[node].value = (end - start + 1) - tree[node].value;
		if (start != end)
		{
			tree[node * 2].lazy = !tree[node * 2].lazy;
			tree[node * 2 + 1].lazy = !tree[node * 2 + 1].lazy;
		}
		tree[node].lazy = 0;
	}
}
int sum(int node, int start, int end, int left, int right)
{
	propatage(node, start, end);

	if (right < start || end < left)
		return (0);
	if (left <= start && end <= right)
		return tree[node].value;
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update_lazy(int node, int start, int end, int left, int right)
{
	propatage(node, start, end);
	int mid = (start + end) / 2;
	if (right < start || end < left)
		return ;
	if (left <= start && end <= right)
	{
		tree[node].value = (end - start + 1) - tree[node].value; //범위의 스위치 개수에서 켜진 스위치 개수를 빼면 꺼진 스위치 개수가 나온다.
		if (start != end)
		{
			tree[node * 2].lazy = !tree[node * 2].lazy;
			tree[node * 2 + 1].lazy = !tree[node * 2 + 1].lazy;
		}
		return ;
	}
	update_lazy(node * 2, start, mid, left, right);
	update_lazy(node * 2 + 1, mid + 1, end, left, right);
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}
int main() {
	FAST;
	int N, M, O, S, T;
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	int tree_size = 1 << (h + 1);
	tree.resize(tree_size + 1, Leaf());

	while (M--)
	{
		cin >> O >> S >> T;
		S--, T--;
		if (O == 0)
		{
			update_lazy(1, 0, N - 1, S, T);
		}
		else
		{
			cout << sum(1, 0, N - 1, S, T) << '\n';
		}
	}
}

