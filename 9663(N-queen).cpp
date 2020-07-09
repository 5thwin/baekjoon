//N-queen
#include<cstdio>
#include<stack>
#include<vector>
#
/*
한 행에 하나씩 퀸을 둔다.
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
	//왼쪽 대각선 아래 방향
	int y = pos.first, x = pos.second;
	y++; x--;
	while (in_range(y, x)) {
		map[y++][x--]++;
	}
	//아래 방향
	y = pos.first, x = pos.second;
	y++;
	while (in_range(y, x)) {
		map[y++][x]++;
	}
	//오른쪽 대각선 아래 방향
	y = pos.first, x = pos.second;
	y++; x++;
	while (in_range(y, x)) {
		map[y++][x++]++;
	}
}
void unset_q(pair<int, int> pos) {
	//왼쪽 대각선 아래 방향
	int y = pos.first, x = pos.second;
	y++; x--;
	while (in_range(y, x)) {
		map[y++][x--]--;
	}
	//아래 방향
	y = pos.first, x = pos.second;
	y++;
	while (in_range(y, x)) {
		map[y++][x]--;
	}
	//오른쪽 대각선 아래 방향
	y = pos.first, x = pos.second;
	y++; x++;
	while (in_range(y, x)) {
		map[y++][x++]--;
	}
}
int solution(int k) {
	int sol = 0; //k번째 퀸을 놓았을 때, 경우의 수
	//스택에서 k번째 퀸을 놓을 자리를 하나를 뽑는다.(k는 0~N-1)
	pair<int, int> pre = st.top(); st.pop();
	//k번째 퀸을 놓을 자리가 없는 경우
	if (pre.first != k) return 0;
	//k번째가 마지막 퀸인 경우
	if (k == N - 1) { return 1; }
	//앞으로 퀸을 놓을 수 없는 자리 세팅
	set_q(pre);

	//k+1 번째 퀸을 놓을 수 있는 자리를 스택에 넣는다.
	for (int i = 0; i < N; i++) {
		if (map[k + 1][i] == 0)
			st.push(make_pair(k + 1, i));
	}
	//k+1번째에 대해서 solution 호출
	
	while (!st.empty() && st.top().first == k + 1) {
		int ret = solution(k + 1);
		sol += ret;
	}
	
	//이전에 놓았던 k번째 퀸을 치운다.
	unset_q(pre);
	return sol;
	
}
int main() {
	
	
	scanf("%d", &N);
	//처음 퀸을 놓을 수 있는 자리 N개
	for (int i = 0; i < N; i++) {
		st.push(make_pair(0, i));
	}
	while (!st.empty()) {
		cnt += solution(0);
	}
	printf("%d", cnt);
	return 0;
}