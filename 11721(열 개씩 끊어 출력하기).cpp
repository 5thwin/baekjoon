#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	int length,start;
	cin >> input;
	length = input.length();
	start = 0;
	while (start < length) {
		cout << input.substr(start, 10) << '\n';
		start += 10;
	}
}