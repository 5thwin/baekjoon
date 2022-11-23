#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(nullptr);            \
	cout.tie(nullptr);
#define MP make_pair

typedef long long ll;
using namespace std;
string expression;
int a = 0, b = 0; // a는 -부호 앞에 나오는 것들의 합, b는 -부호 뒤에 나오는 것들의 합
int main()
{
	FAST;
	// freopen("../../input.txt", "r", stdin);
	cin >> expression;
	// - 부호가 앞에서 한번 나왔으면, 뒤에 있는 수는 다 빼주면 된다.
	int N = expression.size();
	int number = 0;
	int *target = &a; //나중에 '-' 나오면 b로 바꿔줄 예정
	for (int i = 0; i < N; i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			number = number * 10 + (expression[i] - '0');
			if (i == N - 1) //마지막 자리면 현재 number를 바로 처리해준다.
				*target += number;
		}
		else //+, 혹은 - 나온 경우
		{
			*target += number;
			number = 0;
			if (expression[i] == '-' && target == &a) //음수가 나온 이후로부터는 b 에다 더해줌
				target = &b;
		}
	}
	cout << a - b;
}
