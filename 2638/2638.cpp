#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair

typedef long long ll;
using namespace std;

short field[101][101];
int N, M;
bool isOutside[101][101];
//인접해 있는 외부 공기 칸의 개수
int contact[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
stack<pair<int, int>> meltingStack;
void insertInput();
void printOutput();
/*DFS 통해 해당 필드의 0이 밖인지 치즈 내부공간인지 업데이트,
가장자리엔 치즈가 없으므로 0,0과 연결된 부분은 1로 업데이트*/
void updateOutside(int y, int x)
{
	isOutside[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		//이미 방문한 자리라면 스킵
		if (isOutside[ny][nx])
			continue;
		// 1이 근접해 있다면
		if (field[ny][nx] == 1)
		{
			contact[ny][nx]++;
			if (contact[ny][nx] == 2)
			{
				meltingStack.push(MP(ny, nx));
			}
			continue;
		}

		updateOutside(ny, nx);
	}
}
int main()
{
	FAST;
	insertInput();
	int step = 0;
	while (1)
	{
		/*매 과정마다 isOutside와 isMelt를 0으로 초기화하는 과정 필수*/
		memset(isOutside, 0, sizeof(isOutside));
		memset(contact, 0, sizeof(contact));
		/*0,0위치와 연결된 외부를 찾는 동시에, 외부가 2번 이상 인접한 치즈를 meltingStack 저장*/
		updateOutside(0, 0);
		/*녹을 치즈가 남아있지 않으면 긑내기*/
		if (meltingStack.empty())
			break;
		while (!meltingStack.empty())
		{
			/*스택에 저장된 치즈를 0으로 변경*/
			field[meltingStack.top().first][meltingStack.top().second] = 0;
			meltingStack.pop();
		}
		step++;
	}
	cout << step;
}

void insertInput()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> field[i][j];
		}
	}
}
void printOutput()
{
	cout << N << " " << M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << isOutside[i][j] << " ";
		}
		cout << "\n";
	}
}
