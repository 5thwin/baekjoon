#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

class Element{
public:
	int x;
	int y;
	int j;
	Element()
	{
		x = y = j = -1;
	}
	Element(int _x, int _y, int _j)
	{
		x = _x;
		y = _y;
		j = _j;
	}
	void replace(Element elem)
	{
		x = elem.x;
		y = elem.y;
		j = elem.j;
	}
};

int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
bool visit[300][300];

bool valid(int I, int x, int y)
{
	if (x >= I || x < 0)
		return 0;
	if (y >= I || y < 0)
		return 0;
	return 1;
}
int BFS(int I, int srcx, int srcy, int desx, int desy)
{
	queue<Element> qu;
	int jump = 0;
	Element now = Element(srcx, srcy, jump);
	Element next = Element();

	qu.push(now);
	while (!qu.empty())
	{
		now.replace(qu.front());
		qu.pop();
		if (visit[now.x][now.y])
			continue;
		visit[now.x][now.y] = 1;
		if (now.x == desx && now.y == desy)
			return now.j;
		for (int i = 0; i < 8; i++)
		{
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (!valid(I, next.x, next.y))
				continue;
			next.j = now.j + 1;
			qu.push(next);
		}
	}
	return -1;
}
int main()
{
	int T, I, srcx, srcy, desx, desy;
	scanf("%d", &T);
	while (T--)
	{
		memset(visit, 0, sizeof(visit));
		scanf("%d", &I);
		scanf("%d %d", &srcx, &srcy);
		scanf("%d %d", &desx, &desy);
		printf("%d\n", BFS(I, srcx, srcy, desx, desy));
	}
	return 0;
}