//N-queen
#include<cstdio>
#include<stack>
#include<vector>
#
/*
�� �࿡ �ϳ��� ���� �д�.
*/
using namespace std;
int map[15][15];
int N, cnt = 0;
stack< pair<int, int> > st;
bool in_range(int a,int b) {
	if (a < 0 || b < 0 || a >= N || b >= N)
		return false;
	return true;
}

void set_q(pair<int, int> pos) {
	//���� �밢�� �Ʒ� ����
	int y = pos.first, x = pos.second;
	y++; x--;
	while (in_range(y, x)) {
		map[y++][x--]++;
	}
	//�Ʒ� ����
	y = pos.first, x = pos.second;
	y++;
	while (in_range(y, x)) {
		map[y++][x]++;
	}
	//������ �밢�� �Ʒ� ����
	y = pos.first, x = pos.second;
	y++; x++;
	while (in_range(y, x)) {
		map[y++][x++]++;
	}
}
void unset_q(pair<int, int> pos) {
	//���� �밢�� �Ʒ� ����
	int y = pos.first, x = pos.second;
	y++; x--;
	while (in_range(y, x)) {
		map[y++][x--]--;
	}
	//�Ʒ� ����
	y = pos.first, x = pos.second;
	y++;
	while (in_range(y, x)) {
		map[y++][x]--;
	}
	//������ �밢�� �Ʒ� ����
	y = pos.first, x = pos.second;
	y++; x++;
	while (in_range(y, x)) {
		map[y++][x++]--;
	}
}
int solution(int k) {
	int sol = 0; //k��° ���� ������ ��, ����� ��
	//���ÿ��� k��° ���� ���� �ڸ��� �ϳ��� �̴´�.(k�� 0~N-1)
	pair<int, int> pre = st.top(); st.pop();
	//k��° ���� ���� �ڸ��� ���� ���
	if (pre.first != k) return 0;
	//k��°�� ������ ���� ���
	if (k == N - 1) { return 1; }
	//������ ���� ���� �� ���� �ڸ� ����
	set_q(pre);

	//k+1 ��° ���� ���� �� �ִ� �ڸ��� ���ÿ� �ִ´�.
	for (int i = 0; i < N; i++) {
		if (map[k + 1][i] == 0)
			st.push(make_pair(k + 1, i));
	}
	//k+1��°�� ���ؼ� solution ȣ��
	
	while (!st.empty() && st.top().first == k + 1) {
		int ret = solution(k + 1);
		sol += ret;
	}
	
	//������ ���Ҵ� k��° ���� ġ���.
	unset_q(pre);
	return sol;
	
}
int main() {
	
	
	scanf("%d", &N);
	//ó�� ���� ���� �� �ִ� �ڸ� N��
	for (int i = 0; i < N; i++) {
		st.push(make_pair(0, i));
	}
	while (!st.empty()) {
		cnt += solution(0);
	}
	printf("%d", cnt);
	return 0;
}