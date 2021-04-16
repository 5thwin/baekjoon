#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 987654321
using namespace std;

long long R, C, N;
int main()
{
	FAST;
	long long cctv = 0;
	cin >> R >> C >> N;
	cctv = ((R / N) + (R % N == 0 ? 0 : 1)) * ((C / N) + (C % N == 0 ? 0 : 1));
	cout << cctv;
}