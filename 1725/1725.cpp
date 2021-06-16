/*히스토그램*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MAXINT 2000000001
typedef long long ll;
using namespace std;

vector<int> input;
vector<int> tree;

int init(int node, int start, int end)
{
	if (start == end)
		return tree[node] = start;
	int mid = (start + end) / 2;
	int leftidx = init(node * 2, start, mid);
	int rightidx = init(node * 2 + 1, mid + 1, end);
	return tree[node] = (input[leftidx] < input[rightidx]) ? leftidx : rightidx;
}

//left ~ right에서 최소 높이를 가진 인덱스를 찾음
int query(int node, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return -1;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int leftidx = query(node * 2, start, mid, left, right);
	int rightidx = query(node * 2 + 1, mid + 1, end, left, right);
	if (leftidx == -1)
		return rightidx;
	if (rightidx == -1)
		return leftidx;
	return (input[leftidx] < input[rightidx]) ? leftidx : rightidx;
}

int solve(int N, int left, int right)
{
	int lowidx = query(1, 0, N - 1, left, right);
	int curarea = (right - left + 1) * input[lowidx];
	int left_side = -1, right_side = -1;
	if (lowidx != left)
		left_side = solve(N, left, lowidx - 1);
	if (lowidx != right)
		right_side = solve(N, lowidx + 1, right);
	return max(curarea, max(left_side, right_side));
}
int main()
{
	FAST;
	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}
	int H = (int)ceil(log2(N));
	int TreeSize = 1 << (H + 1);
	tree.resize(TreeSize);
	init(1, 0, N - 1);
	cout << solve(N, 0, N - 1) << "\n";
	return (0);
}
