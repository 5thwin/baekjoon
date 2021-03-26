#include <iostream>
#include <string>
#define BUFFER_SIZE 2000000
using namespace std;

template <typename T> class Queue
{
private:
	T *buffer;
	int f_idx;
	int b_idx;
	int size = 0;
public:
	Queue()
	{
		buffer = new T[BUFFER_SIZE];
		f_idx = 0;
		b_idx = 0;
		size = 0;
	}
	~Queue()
	{
		delete[] buffer;
	}
	void push(T value)
	{
		if (size == BUFFER_SIZE)
			return;
		buffer[b_idx] = value;
		size++;
		b_idx = (b_idx + 1) % BUFFER_SIZE;
	}
	int pop()
	{
		int ret;
		if (size == 0)
			return (-1);
		ret = buffer[f_idx];
		f_idx = (f_idx + 1) % BUFFER_SIZE;
		size--;
		return (ret);
	}
	int qsize()
	{
		return size;
	}
	int empty()
	{
		if (size == 0)
			return (1);
		return (0);
	}
	int front()
	{
		if (empty())
			return (-1);
		return (buffer[f_idx]);
	}
	int back()
	{
		if (empty())
			return (-1);
		return (buffer[(b_idx - 1 + BUFFER_SIZE) % BUFFER_SIZE]);
	}
};
int str2int(string str)
{
	int ret = 0, i = 0;
	int len = str.size();
	while (i < len)
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, X;
	string command;
	Queue<int> qu;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		getline(cin, command);
		if (command.substr(0, 4) == "push")
		{
			X = str2int(command.substr(5));
			qu.push(X);
		}
		if (command.substr(0, 3) == "pop")
			cout << qu.pop() << "\n";
		if (command.substr(0, 4) == "size")
			cout << qu.qsize() << "\n";
		if (command.substr(0, 5) == "empty")
			cout << qu.empty() << "\n";
		if (command.substr(0, 5) == "front")
			cout << qu.front() << "\n";
		if (command.substr(0, 4) == "back")
			cout << qu.back() << "\n";
	}
}