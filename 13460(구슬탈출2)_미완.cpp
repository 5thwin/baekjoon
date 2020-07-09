//구슬탈출2
//N = 세로 M = 가로
#include <cstdio>

using namespace std;

int N, M;
char map[10][10];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) {
		scanf("%s", map[n]);
	}
	
}
