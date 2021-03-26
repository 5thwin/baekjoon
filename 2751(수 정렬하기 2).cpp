#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int input, N;
	vector<int> v;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
		printf("%d\n", v[i]);
}