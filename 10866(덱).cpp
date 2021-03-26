#include <iostream>
#include <string>
#define BUFFER_SIZE 10001

using namespace std;
/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.*/
template <typename T>
class Deck
{
private:
	T* buf;
	int frt_idx;
	int bak_idx;
	int size;
public:
	Deck()
	{
		buf = new T[BUFFER_SIZE];
		frt_idx = 0;
		bak_idx = 1;
		size = 0;
	}
	~Deck()
	{
		delete buf;
	}
	void push_front(T val)
	{
		if (size == BUFFER_SIZE)
			return;
		buf[frt_idx] = val;
		/*if (frt_idx == bak_idx)
			bak_idx = (bak_idx + 1) % BUFFER_SIZE;
		*/
		size++;
		frt_idx = (frt_idx - 1 + BUFFER_SIZE) % BUFFER_SIZE;
	}
	void push_back(T val)
	{
		if (size == BUFFER_SIZE)
			return;
		buf[bak_idx] = val;
		/*if (frt_idx == bak_idx)
			frt_idx = (frt_idx - 1 + BUFFER_SIZE) % BUFFER_SIZE;
		*/
		size++;
		bak_idx = (bak_idx + 1) % BUFFER_SIZE;
	}
	T pop_front()
	{
		if (size == 0)
			return (-1);
		frt_idx = (frt_idx + 1) % BUFFER_SIZE;
		size--;
		return (buf[frt_idx]);
	}
	T pop_back()
	{
		if (size == 0)
			return (-1);
		bak_idx = (bak_idx - 1 + BUFFER_SIZE) % BUFFER_SIZE;
		size--;
		return (buf[bak_idx]);
	}
	T front()
	{
		if (size == 0)
			return (-1);
		return (buf[(frt_idx + 1) % BUFFER_SIZE]);
	}
	T back()
	{
		if (size == 0)
			return (-1);
		return (buf[(bak_idx - 1 + BUFFER_SIZE) % BUFFER_SIZE]);
	}
	int decsize()
	{
		return size;
	}
	bool empty()
	{
		if (size == 0)
			return (1);
		else
			return (0);
	}
};
int str2int(string str)
{
	int ret = 0;
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		ret *= 10;
		ret += str[i] - '0';
	}
	return ret;
}
int main()
{
	int N;
	string cmd;
	Deck<int> dec;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		
		getline(cin, cmd);
		if (cmd.substr(0, 10) == "push_front")
			dec.push_front(str2int(cmd.substr(11)));
		else if (cmd.substr(0, 9) == "push_back")
			dec.push_back(str2int(cmd.substr(10)));
		else if (cmd.substr(0, 9) == "pop_front")
			cout << dec.pop_front() << '\n';
		else if (cmd.substr(0, 8) == "pop_back")
			cout << dec.pop_back() << '\n';
		else if (cmd.substr(0, 4) == "size")
			cout << dec.decsize() << '\n';
		else if (cmd.substr(0, 5) == "empty")
			cout << dec.empty() << '\n';
		else if (cmd.substr(0, 5) == "front")
			cout << dec.front() << '\n';
		else if (cmd.substr(0, 4) == "back")
			cout << dec.back() << '\n';
	}
}