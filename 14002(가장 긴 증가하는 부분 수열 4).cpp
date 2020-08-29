#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

int N;
int arr[1000];
int dp[1000][2]; // 첫번째에 최대 길이, 두번째에 이전 순서의 배열 값
int maxlen = 1, last;
stack<int> st;
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0][0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i][0] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
			{
				if (dp[i][0] < dp[j][0] + 1) {
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = j;
				}
			}
		}
		if (maxlen< dp[i][0]) {
			maxlen = dp[i][0];
			last = i;
		}
	}
	printf("%d\n", maxlen);
	int cur = last;
	while(cur != -1){
		st.push(arr[cur]);
		cur = dp[cur][1];
	}
	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}
}