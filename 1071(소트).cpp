#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#define MP make_pair
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int table[1002]; //table[n] : n 이 몇번나왔는지 세서 저장
int main()
{
	cin >> N;
	int input;
	int maxval = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		table[input]++;
		maxval = max(maxval, input);
	}
	for (int i = 0; i <= maxval; i++)
	{
		while (table[i] > 0)
		{
			/*다음 숫자가 있는지 확인한다.*/
			if (table[i + 1] == 0) /*i+1의 개수가 0이면 있는 것 다 출력*/
			{
				cout << i << " ";
				table[i]--;
				continue;
			}
			/*다음 숫자가 있으면 그 다음으로 큰 숫자를 껴놓기*/
			int next;
			for (next = i + 2; next <= maxval; next++)
			{
				if (table[next] > 0) 
				{
					while (table[i])
					{
						cout << i << " ";
						table[i]--;
					}
					cout << next << " ";
					table[i]--;
					table[next]--;
					break;
				}
			}
			if (next == maxval + 1) //만약 더 큰게 없었을 때, i + 1 먼저 출력
			{
				cout << i + 1 << " ";
				table[i + 1]--;
			}
		}
	}
}