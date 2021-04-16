#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
using namespace std;

int N;
int arr[10][10];
int sum[10];
void ft_print(int n, int digit)
{
	if (digit == 0)
	{
		cout << n;
		return;
	}
	int a_sum = arr[digit][0];
	for (int i = 1; i < 10; i++)
	{
		a_sum += arr[digit][i];
		if (n < a_sum)
		{
			cout << i;
			n -= (a_sum - arr[digit][i]);
			ft_print(n, digit - 1);
			return;
		}
	}
}
int main()
{
	FAST;
	for (int i = 0; i < 10; i++)
		arr[0][i] = 1;
	sum[0] = 10;
	for (int i = 1; i < 11; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < j; k++)
				arr[i][j] += arr[i - 1][k];
			sum[i] += arr[i][j];
		}
	}
	int total = 0;
	for (int i = 0; i < 10; i++)
		total += sum[i];
	cin >> N;
	if (N >= total)
		cout << "-1";
	else if (N <= 9)
		cout << N << "\n";
	else
	{
		int digit, n;
		n = N;
		for (digit = 0; digit < 10; digit++)
		{
			if (n < sum[digit])
				break;
			n -= sum[digit];
		}
		ft_print(n, digit);
	}
}

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
#define INF 987654321
#define MAXNODE 300000
#define ABS(X) (X) < 0 ? -(X) : (X)
typedef long long ll;
using namespace std;

vector<vector<pair<int,int>>> graph;
int N;
int Z;
struct ST
{
    int node;
    long long cost;
    long long cnt;
    ST(int n, ll co, ll cn)
    {
        node = n;
        cost = co;
        cnt = cn;
    }
};

long long solve(int node, long long target) // BFS
{
    queue<ST> qu;
    qu.push(ST(node, 0, 0));
    long long ans = INF;
    while (!qu.empty())
    {
        int here = qu.front().node;
        ll cost = qu.front().cost;
        ll cnt = qu.front().cnt;
        qu.pop()
        if (cost == target)
        {
            ans = min(ans, cnt);
            continue;
        }
        int len = graph[here].size();
        /*인접노드 탐색*/
        for (int i = 0; i < len; i++)
        {
            int there = graph[here][i].front;
            ll ncost = cost + graph[here][i].second;
            if (ncost > target)
                continue;
            qu.push(ST(there, ncost, cnt + 1));
        }
        /*순간이동*/
        for (int i = 0; i < N; i++)
        {
            if (i == here)
                continue;
            
        }
    }
}
vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
    N = n;
    Z = z;
    vector<long long> answer;
    dp.resize(N + 1, vector(Z + 1, INF));
    graph.resize(n + 1);
    int len = roads.size();
    for (int i = 0; i < len; i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        int w = roads[i][2];
        graph[u].push_back(v,w);
    }
    
    return answer;
}
/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
#define INF 987654321
#define MAXNODE 300000
#define ABS(X) (X) < 0 ? -(X) : (X)
typedef long long ll;
using namespace std;

vector<vector<pair<int,int>>> graph;
int N;
int Z;
struct ST
{
    int node;
    long long cost;
    long long cnt;
    ST(int n, ll co, ll cn)
    {
        node = n;
        cost = co;
        cnt = cn;
    }
};

long long solve(int node, long long target) // BFS
{
    queue<ST> qu;
    qu.push(ST(node, 0, 0));
    long long ans = INF;
    while (!qu.empty())
    {
        int here = qu.front().node;
        ll cost = qu.front().cost;
        ll cnt = qu.front().cnt;
        qu.pop()
        if (cost == target)
        {
            ans = min(ans, cnt);
            continue;
        }
        int len = graph[here].size();
        /*인접노드 탐색*/
for (int i = 0; i < len; i++)
{
    int there = graph[here][i].front;
    ll ncost = cost + graph[here][i].second;
    if (ncost > target)
        continue;
    qu.push(ST(there, ncost, cnt + 1));
}
/*순간이동*/
for (int i = 0; i < N; i++)
{
    if (i == here)
        continue;

}
    }
}
vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
    N = n;
    Z = z;
    vector<long long> answer;
    dp.resize(N + 1, vector(Z + 1, INF));
    graph.resize(n + 1);
    int len = roads.size();
    for (int i = 0; i < len; i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        int w = roads[i][2];
        graph[u].push_back(v, w);
    }

    return answer;
}

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MP make_pair
#define INF 987654321
#define MAXNODE 300000
#define ABS(X) (X) < 0 ? -(X) : (X)
typedef long long ll;
using namespace std;

vector<vector<pair<int,int>>> graph;
int N;
int Z;
struct ST
{
    int node;
    long long cost;
    long long cnt;
    ST(int n, ll co, ll cn)
    {
        node = n;
        cost = co;
        cnt = cn;
    }
};

long long solve(int node, long long target) // BFS
{
    queue<ST> qu;
    qu.push(ST(node, 0, 0));
    long long ans = INF;
    while (!qu.empty())
    {
        int here = qu.front().node;
        ll cost = qu.front().cost;
        ll cnt = qu.front().cnt;
        qu.pop()
        if (cost == target)
        {
            ans = min(ans, cnt);
            continue;
        }
        int len = graph[here].size();
        /*인접노드 탐색*/
for (int i = 0; i < len; i++)
{
    int there = graph[here][i].front;
    ll ncost = cost + graph[here][i].second;
    if (ncost > target)
        continue;
    qu.push(ST(there, ncost, cnt + 1));
}
/*순간이동*/
for (int i = 0; i < N; i++)
{
    if (i == here)
        continue;

}
    }
}
vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
    N = n;
    Z = z;
    vector<long long> answer;
    dp.resize(N + 1, vector(Z + 1, INF));
    graph.resize(n + 1);
    int len = roads.size();
    for (int i = 0; i < len; i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        int w = roads[i][2];
        graph[u].push_back(v, w);
    }

    return answer;
}
*/