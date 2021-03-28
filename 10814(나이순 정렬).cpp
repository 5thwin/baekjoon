#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Member
{
	int age;
	int ord;
	string name;
	Member(int a, int b, string s)
	{
		age = a;
		ord = b;
		name = s;
	}
};

bool comp(const Member& a, const Member& b)
{
	if (a.age < b.age)
		return true;
	else if (a.age == b.age)
		return (a.ord < b.ord);
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, age;
	string name;
	vector<Member> arr;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		arr.push_back(Member(age, i, name));
	}
	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].age << " " << arr[i].name << "\n";
	}
}