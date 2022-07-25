#include <iostream>
#include <cassert>
using namespace std;

class Stack
{
private:
	int *array;
	int size;
	// top1 is the top of  the stack starting from first
	// top2 is the top of the stack starting from last
	int top1, top2;

public:
	Stack(int size)
	{
		this->size = size;
		this->array = new int[size];
		this->top1 = -1;
		this->top2 = size;
	}
	bool isEmpty(int sid)
	{
		if (sid == 1)
		{
			return top1 == -1;
		}
		else if (sid == 2)
		{
			return top2 == size;
		}
	}
	bool isFull(int sid)
	{
		return top2 - top1 <= 1;
	}
	void push(int sid, int x)
	{
		if (sid == 1)
		{
			assert(!isFull(1));

			array[++top1] = x;
		}
		else if (sid == 2)
		{
			assert(!isFull(2));
			array[--top2] = x;
		}
	}
	int pop(int sid)
	{
		if (sid == 1)
		{
			assert(!isEmpty(1));

			return array[top1--];
		}
		else if (sid == 2)
		{
			assert(!isEmpty(2));
			return array[top2++];
		}
	}
	int peek(int sid)
	{
		if (sid == 1)
		{
			assert(!isEmpty(1));
			return array[top1];
		}
		else if (sid == 2)
		{
			assert(!isEmpty(2));
			return array[top2];
		}
	}
	void display()
	{
		cout << "\t\t\t the stack 1 \t\t\t" << endl;
		for (int i = top1; i >= 0; i--)
		{
			cout << array[i] << endl;
		}
		cout << "\t\t\t the stack 2 \t\t\t" << endl;
		for (int i = top2; i < size; i++)
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

	Stack stk(10);
	stk.push(2, 5);
	stk.push(2, 6);
	stk.pop(2);
	stk.push(2, 7);
	stk.push(2, 9);

	stk.push(1, 4);
	cout << "stk.peek(1): " << stk.peek(1) << endl;
	cout << "stk.peek(2): " << stk.peek(2) << endl;
	stk.push(1, 6);
	stk.push(1, 8);

	stk.push(1, 12);
	stk.pop(1);

	stk.push(2, 3);
	stk.display();

	return 0;
}
