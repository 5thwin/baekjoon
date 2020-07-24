#include<cstdio>
#include<vector>
typedef long long ll;

using namespace std;

vector<ll>* order(ll a, ll b, ll c) {
	vector<ll>* ret = new vector<ll>;
	if (a > b&& a > c) {
		ret->push_back(a*a);
		ret->push_back(b*b);
		ret->push_back(c*c);
		return ret;
	}
	if (a < b&& b > c) {
		ret->push_back(b * b);
		ret->push_back(a * a);
		ret->push_back(c * c);
		return ret;
	}
	ret->push_back(c * c);
	ret->push_back(b * b);
	ret->push_back(a * a);
	return ret;
}
int main() {
	ll a, b, c;
	vector<ll>* odr = new vector<ll>;
	while (1) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a + b +c == 0)break;
		odr = order(a, b, c);
		if (odr->at(0) == odr->at(1) + odr->at(2))
			printf("right\n");
		else
			printf("wrong\n");
		odr->clear();
	}
}