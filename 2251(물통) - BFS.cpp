#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

bool visit[200][200][200];
int A, B, C;
struct Cup
{
	int a;
	int b;
	int c;
	Cup(int x, int y, int z) { a = x, b = y, c = z; }
	bool operator<(const Cup &cup)
	{
		return (c < cup.c);
	}
};
vector<Cup> vc;

void BFS(Cup init)
{
	queue<Cup> qu;
	qu.push(init);
	int ca,cb,cc, na, nb, nc;
	while (!qu.empty())
	{
		ca = qu.front().a;
		cb = qu.front().b;
		cc = qu.front().c;
		qu.pop();
		if (visit[ca][cb][cc])
			continue;
		visit[ca][cb][cc] = 1;
		if (ca == 0)
			vc.push_back(Cup(ca, cb, cc));
		/*C -> A*/
		if (ca < A)
		{
			na = min(ca + cc, A);
			nc = max(0,  (ca + cc - A));
			qu.push(Cup(na, cb, nc));
		}
		/*A -> C*/
		if (cc < C)
		{
			nc = min(ca + cc, C);
			na = max(0, (ca + cc - C));
			qu.push(Cup(na, cb, nc));
		}
		/*C -> B*/
		if (cb < B)
		{
			nb = min(cb + cc, B);
			nc = max(0, (cb + cc - B));
			qu.push(Cup(ca, nb, nc));
		}
		/*B -> C*/
		if (cc < C)
		{
			nc = min(cb + cc, C);
			nb = max(0, (cb + cc - C));
			qu.push(Cup(ca, nb, nc));
		}
		/*B -> A*/
		if (ca < A)
		{
			na = min(ca + cb, A);
			nb = max(0, (ca + cb - A));
			qu.push(Cup(na, nb, cc));
		}
		/*A -> B*/
		if (cb < B)
		{
			nb = min(ca + cb, B);
			na = max(0, (ca + cb - B));
			qu.push(Cup(na, nb, cc));
		}
	}
}
int main()
{
	FAST;
	cin >> A >> B >> C;
	BFS(Cup(0, 0, C));
	sort(vc.begin(), vc.end());
	int len = vc.size();
	for (int i = 0; i < len; i++)
	{
		cout << vc[i].c << " ";
	}
}