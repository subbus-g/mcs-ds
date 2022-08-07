#include <iostream>
#include <cassert>
using namespace std;

class Queue
{
	int *array, capacity, front, rear, size;
	void display()
	{
		cout << "queue array:  ";
		if (front == -1 || rear == -1)
		{
			cout << "EMPTY";
		}
		else
		{
			/* code */
			for (int i = front; i <= rear; i++)
			{
				cout << array[i] << ' ';
			}
		}

		cout << endl;
	}

public:
	Queue(int capacity)
	{
		this->capacity = capacity;
		this->array = new int[capacity];
		front = rear = -1;
		size = 0;
	}
	bool isEmpty()
	{
		return !size;
	}
	bool isFull()
	{
		return size == capacity;
	}
	void enqueue(int x)
	{
		if (isFull())
		{
			cout << "queue is full" << endl;
			return;
		}
		if (isEmpty())
		{
			front = rear = 0;
		}
		else
		{
			rear++;
		}
		array[rear] = x;
		size++;
		cout << "enqueued " << x << endl;
		cout << "front: " << front << endl;
		cout << "rear: " << rear << endl;
		display();
		cout << endl;
	}
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "queue is empty";
			return;
		}
		if (front == 0 && rear == 0)
		{
			front = rear = -1;
			size = 0;
		}
		else
		{
			front++;
			size--;
		}
		cout << "dequeued " << endl;
		cout << "front: " << front << endl;
		cout << "rear: " << rear << endl;
		display();
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	Queue q(5);
	q.enqueue(2);
	q.enqueue(5);
	q.enqueue(7);
	q.dequeue();
	q.dequeue();
	q.dequeue();

	return 0;
}
