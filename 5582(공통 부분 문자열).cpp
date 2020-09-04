//이건 좀 어렵네
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dict[26];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	string s1, s2;
	int idx,s1_ord, longest = 0;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		idx = s1[i] - 'A';
		dict[idx].push_back(i);
	}
	vector<vector<int>> vec(s2.length(), vector<int>(s1.length(),0));
	for (int i = 0; i < s2.length(); i++) {
		idx = s2[i] - 'A';
		for (int j = 0; j < dict[idx].size(); j++) {
			s1_ord = dict[idx][j];
			if (s1_ord == 0 || i == 0)
				vec[i][s1_ord] = 1;
			else
				vec[i][s1_ord] = vec[i - 1][s1_ord - 1] + 1;
			longest = max(longest, vec[i][s1_ord]);
		}
	}
	cout << longest << "\n";

}