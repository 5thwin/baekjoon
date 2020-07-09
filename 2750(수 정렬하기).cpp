//Heap sort 
#include<cstdio>
#include<algorithm>


void heap(int *heap_tree, int n) {
	int* temp = &heap_tree[0];
	for (int i = 2; i <= n; i++) {
		int child = i;
		while (child > 1) {
			int root = child / 2;
			if (heap_tree[child] > heap_tree[root]) {
				*temp = heap_tree[child];
				heap_tree[child] = heap_tree[root];
				heap_tree[root] = *temp;
			}
			child = root;
		}
	}
}
void pop(int* heap_tree, int n) {
	int* temp= &heap_tree[0];
	*temp = heap_tree[1];
	heap_tree[1] = heap_tree[n];
	heap_tree[n] = *temp;
	int root = 1;
	while (root*2 < n) {
		int left = root * 2, right = left + 1;
		if (heap_tree[left] < heap_tree[right] && right < n) { //오른쪽이 클때
			if (heap_tree[root] > heap_tree[right])
				break;
			*temp = heap_tree[root];
			heap_tree[root] = heap_tree[right];
			heap_tree[right] = *temp;
			root = right;
		}
		else { //왼쪽이 클때
			if (heap_tree[root] > heap_tree[left])
				break;
			*temp = heap_tree[root];
			heap_tree[root] = heap_tree[left];
			heap_tree[left] = *temp;
			root = left;
		}
	}
}
int main() {
	int heap_tree[1001], N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &heap_tree[i]);
	}
	heap(heap_tree, N);

	for (int i = 0; i < N; i++) {
		pop(heap_tree, N - i);
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", heap_tree[i + 1]);
	}

}
