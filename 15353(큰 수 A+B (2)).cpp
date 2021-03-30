#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1, s2;
	vector<char> rev1, rev2, out;
	int tmp = 0, len1, len2, mxlen, olen = 0;

	cin >> s1 >> s2;
	len1 = s1.size();
	len2 = s2.size();
	mxlen = max(len1, len2);
	rev1.resize(mxlen, '0');
	rev2.resize(mxlen, '0');
	out.resize(mxlen + 1);
	for (int i = 0; i < len1; i++)
		rev1[i] = s1[len1 - 1 - i];
	for (int i = 0; i < len2; i++)
		rev2[i] = s2[len2 - 1 - i];
	for (olen = 0; olen < mxlen; olen++)
	{
		tmp += (rev1[olen] - '0') + (rev2[olen] - '0');
		out[olen] = (tmp % 10) + '0';
		tmp = tmp /= 10;
	}
	if (tmp)
		out[olen++] = (tmp % 10) + '0';
	while (olen - 1 >= 0)
		cout << out[--olen];

}