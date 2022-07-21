#include <iostream>
#include <cassert>
using namespace std;

class Stack
{
private:
	int *array;
	int size;
	int added_elements;

public:
	Stack(int size)
	{
		this->size = size;
		this->array = new int[size];
		this->added_elements = 0;
	}
	// O(1)-time, O(1)-memory
	bool isEmpty()
	{
		return added_elements == 0;
	}
	// O(1)-time, O(1)-memory
	bool isFull()
	{
		return added_elements == size;
	}
	// O(n)-time, O(1)-memory
	bool push(int x)
	{
		if (isFull())
			return false;
		if (!added_elements)
		{
			array[0] = x;
			added_elements++;
			return true;
		}
		// create hole at 0th postion by shifting elements right
		for (int i = added_elements; i > 0; i--)
		{
			array[i] = array[i - 1];
		}
		array[0] = x;
		added_elements++;
		return true;
	}
	// O(n)-time, O(1)-memory
	bool pop()
	{
		if (isEmpty())
		{
			return false;
		}
		// fill the hole at 0th position by shifting elements left
		for (int i = 0; i < added_elements - 1; i++)
		{
			array[i] = array[i + 1];
		}
		added_elements--;
		return true;
	}
	// O(1)-time, O(1)-memory
	bool peek()
	{
		if (isEmpty())
		{
			return false;
		}
		//	cout << "peek: " << array[0] << endl;
		return true;
	}
	void display()
	{
		cout << "the stack is ";
		for (int i = 0; i < added_elements; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
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
	cout << stk.push(10);
	cout << stk.push(20);
	cout << stk.push(30);
	stk.display();
	cout << "stk.isFull()  " << stk.isFull() << endl;
	cout << "stk.peek() " << stk.peek() << endl;
	cout << "stk.pop() " << stk.pop() << endl;
	stk.display();
	cout << "stk.pop() " << stk.pop() << endl;
	stk.display();
	cout << "stk.isFull()  " << stk.isFull() << endl;

	return 0;
}
