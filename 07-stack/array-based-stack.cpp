#include <iostream>
using namespace std;

class Stack
{
	int *stack;
	int capacity, top = -1;

public:
	Stack(int capacity) : capacity(capacity)
	{
	}
	bool isEmpty()
	{
		return top == -1;
	}
	bool isFull()
	{
		return top == capacity - 1;
	}
	int peek()
	{
		return stack[top];
	}
	int pop()
	{
		return stack[top--];
	}
	void push(int x)
	{
		if (isFull())
		{
			cout << "FULLL" << endl;
		}
		else
		{
			stack[++top] = x;
			cout << "inserted " << x << endl;
		}
	}
};
int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	Stack stk(3);
	stk.push(10);
	stk.push(20);
	stk.push(30);
	cout << "stk.isFull()  " << stk.isFull() << endl;
	cout << stk.peek() << endl;
	cout << stk.pop() << endl;

	cout << stk.isFull() << endl;

	return 0;
}
