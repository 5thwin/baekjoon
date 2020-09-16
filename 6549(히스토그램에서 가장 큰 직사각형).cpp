#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#define INF 1000000001
typedef long long ll;
using namespace std;

vector<int> tree, input;
int N;
int init(vector<int>& _tree, vector<int>& _input, int node, int start, int end) { //최솟값의 위치를 저장
	if (start == end) {return _tree[node] = start; }
	int mid = (start + end) / 2;
	int left_index = init(_tree, _input, node * 2, start, mid);
	int right_index = init(_tree, _input, node * 2 + 1, mid + 1, end);
	if (_input[left_index] <= _input[right_index])
		return _tree[node] = left_index;
	else
		return _tree[node] = right_index;
}
int min_query(int left, int right, int node, int start, int end) {
	if (right < start || end < left) return -1;
	if (left <= start && end <= right) {
		return tree[node]; }
	int mid = (start + end) / 2;
	int left_index = min_query(left, right, node * 2, start, mid);
	int right_index = min_query(left, right, node* 2 + 1, mid + 1, end);
	if (left_index == -1)
		return right_index;
	if (right_index == -1)
		return left_index;
	
	if (input[left_index] <= input[right_index])
		return left_index;
	else
		return right_index;
}
ll largest(int left, int right) { // 0, N-1로 시작
	int min_index = min_query(left, right, 1, 0, N - 1);
	ll area = (ll)input[min_index] * (ll)(right - left + 1);

	if (min_index - 1 >= left)
	{
		area = max(area, largest(left, min_index - 1));
	}
	if (min_index + 1 <= right) {
		area = max(area, largest(min_index + 1, right));
	}
	return area;
}
int main() {
	while (1) {
		scanf("%d", &N);
		if (N == 0)break;
		ll h = ceil(log2(N)) + 1;
		tree.resize(pow(2, h) + 1);
		input.resize(N, INF);
		for (int i = 0; i < N; i++) {
			scanf("%d", &input[i]);
		}
		init(tree, input, 1, 0, N - 1);

		/*tree 확인*/
		/*int node = 1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < pow(2, i); j++)
				printf("%d ", tree[node++]);
			printf("\n");
		}*/
		printf("%lld\n", largest(0, N - 1));
	}
}
