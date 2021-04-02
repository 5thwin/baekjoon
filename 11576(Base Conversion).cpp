#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	int A, B, m, num;
	stack<int> ans;
	scanf("%d %d %d", &A, &B, &m);

	int to_dec = 0;

	while (m--) {
		scanf("%d", &num);
		to_dec += num * pow(A, m);
	}
	int div = to_dec;

	//10진법 -> b진법
	while (div) {
		ans.push(div % B);
		div /= B;
	}

	//stack에 있는 값 하나씩 출력
	while (!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}

	return 0;
}