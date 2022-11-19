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

string input;
int N;
bool isPalindrome[2500][2500];
bool isVisit[2500][2500]; //방문했는지 여부
/*isPalindrome[a][b] = a~b 문자열이 팰린드롬인지 확인
isPalindrome[a][b] = input[a]==input[b] && isPalindrome[a+1][b-1]
*/
bool solvePalindrome(int start, int end)
{
	if (start > end)
		return false;
	bool &ref = isPalindrome[start][end];
	bool &check = isVisit[start][end];
	if (check)
		return ref;
	check = true;
	if (start == end)
		return ref = true;
	solvePalindrome(start + 1, end);
	solvePalindrome(start, end - 1);
	if (input[start] == input[end] && end - start == 1)
		return ref = true;
	if (input[start] == input[end] && solvePalindrome(start + 1, end - 1)) //앞과 뒤가 같고, 그 사이 역시 팰린드롬이라면
		return ref = true;
	return ref = false;
}

int countSeperate[2500]; // countSeperate[k] : 0~k까지 팰린드롬 분할하는 경우 최소로 분할할 수 있는 개수
/*countSeperate[k] = (l = 0~k) =>
l~k가 팰린드롬인 경우
 countSeperate[k] = min(countSeperate[k-1] + 1,countSeperate[l-1] + 1)

*/
void solveSeperate()
{
	countSeperate[0] = 1;
	for (int k = 1; k < N; k++)
	{
		countSeperate[k] = countSeperate[k - 1] + 1;
		for (int l = 0; l < k; l++)
		{
			if (isPalindrome[l][k] == true)
			{
				if (l == 0)
					countSeperate[k] = 1;
				else
					countSeperate[k] = min(countSeperate[l - 1] + 1, countSeperate[k]);
			}
		}
	}
}

int main()
{
	FAST;
	cin >> input;
	N = input.size();
	solvePalindrome(0, N - 1);
	solveSeperate();
	cout << countSeperate[N - 1];
}
