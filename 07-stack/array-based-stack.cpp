#include <iostream>
#include <cassert>
using namespace std;

class Stack
{
private:
	int *array;
	int size;
	// here top refers to "index" of the top element not the top element itself
	int top;

public:
	Stack(int size)
	{
		this->size = size;
		this->array = new int[size];
		this->top = -1;
	}
	bool isEmpty()
	{
		return top == -1;
	}
	bool isFull()
	{
		return top == size - 1;
	}
	void push(int x)
	{
		assert(!isFull());
		array[++top] = x;
	}
	int pop()
	{
		assert(!isEmpty());
		return array[top--];
	}
	int peek()
	{
		assert(!isEmpty());
		return array[top];
	}
	void display()
	{
		cout << "the stack is " << endl;
		for (int i = top; i >= 0; i--)
		{
			cout << array[i] << endl;
		}
	}
	~Stack()
	{
		delete[] array;
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
	stk.display();
	cout << "stk.isFull()  " << stk.isFull() << endl;
	cout << stk.peek() << endl;
	cout << stk.pop() << endl;

	cout << stk.isFull() << endl;

	return 0;
}
