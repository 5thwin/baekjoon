#include<iostream>
#include<cstring>

typedef unsigned long long ll;
using namespace std;

ll koong[68];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i ,input;
	cin >> N;
	koong[0] = koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;
	for (i = 4; i < 68; i++)
	{
		koong[i] = koong[i - 4] +koong[i - 3] + koong[i - 2] + koong[i - 1];
	}
	for (i = 0; i < N; i++) {
		cin >> input;
		cout << koong[input] << "\n";
	}
}