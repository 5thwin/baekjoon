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
void propagate(int node, int start, int end)
{
	if (tree[node].lazy != 0)
	{
		//lazy 확인하고 update
		tree[node].value = (end - start + 1) - tree[node].value;
		//자식 노드에게 lazy 전파
		if (start != end)
		{
			tree[node * 2].lazy = !tree[node * 2].lazy;
			tree[node * 2 + 1].lazy = !tree[node * 2 + 1].lazy;
		}
		//현재 노드의 lazy 초기화
		tree[node].lazy = 0;
	}
}
int sum(int node, int start, int end, int left, int right)
{
	//propagation
	propagate(node, start, end);

	//범위에 속하지 않으면 무시
	if (right < start || end < left)
		return (0);
	//현재 노드가 범위에 속해있으면 노드이 value를 리턴
	if (left <= start && end <= right)
		return tree[node].value;
	int mid = (start + end) / 2;
	//분할탐색
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update_lazy(int node, int start, int end, int left, int right)
{
	//propagation
	propagate(node, start, end);
	int mid = (start + end) / 2;
	//범위에 속하지 않으면 무시
	if (right < start || end < left)
		return ;
	//현재 노드가 범위에 완전히 속한 경우
	if (left <= start && end <= right)
	{
		//현재 노드의 value를 업데이트
		tree[node].value = (end - start + 1) - tree[node].value; //범위의 스위치 개수에서 켜진 스위치 개수를 빼면 꺼진 스위치 개수가 나온다.
		//자식 노드가 있으면 자식에게 lazy 전파
		if (start != end)
		{
			tree[node * 2].lazy = !tree[node * 2].lazy;
			tree[node * 2 + 1].lazy = !tree[node * 2 + 1].lazy;
		}
		//리턴
		return ;
	}
	//범위를 분할하여 자식을 각각 업데이트
	update_lazy(node * 2, start, mid, left, right);
	update_lazy(node * 2 + 1, mid + 1, end, left, right);
	//업데이트된 자식의 value를 기반으로 업데이트
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

