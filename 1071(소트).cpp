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
int table[1002]; //table[n] : n �� ������Դ��� ���� ����
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
			/*���� ���ڰ� �ִ��� Ȯ���Ѵ�.*/
			if (table[i + 1] == 0) /*i+1�� ������ 0�̸� �ִ� �� �� ���*/
			{
				cout << i << " ";
				table[i]--;
				continue;
			}
			/*���� ���ڰ� ������ �� �������� ū ���ڸ� ������*/
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
			if (next == maxval + 1) //���� �� ū�� ������ ��, i + 1 ���� ���
			{
				cout << i + 1 << " ";
				table[i + 1]--;
			}
		}
	}
}