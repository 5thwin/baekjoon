#include <iostream>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
using namespace std;

ll A, B, C;
ll power(ll a, ll p)
{
	if (p == 0)
		return (1);
	ll tmp = power(a, p / 2) % C;
	if (p % 2 == 0)
		return (tmp * tmp) % C;
	else
		return (((tmp * tmp) % C) * (a % C)) % C;
}
int main()
{
	FAST;
	cin >> A >> B >> C;
	cout << power(A, B);
}