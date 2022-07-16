#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;

	Node(int data) : data(data), next(nullptr)
	{
	}
};
class LinkedList
{
private:
	Node *sentinel;

public:
	LinkedList()
	{
		sentinel = new Node(-1);
	}
	void print()
	{
		if (!sentinel->next)
		{
			cout << "EMPTY" << endl;
			return;
		}
		for (auto ptr = sentinel->next; ptr; ptr = ptr->next)
		{
			cout << ptr->data << " ";
		}
		cout << endl;
	}
	void insert_end(int x) // O(n)-time, O(1)-memory
	{
		Node *ptr;
		for (ptr = sentinel; ptr->next; ptr = ptr->next)
		{
		}
		ptr->next = new Node(x);

		// if (!head)
		// {
		// 	head = new Node(x);
		// 	tail = head;
		// 	head->next = nullptr;
		// 	return;
		// }
		// auto new_node = new Node(x);
		// tail->next = new_node;
		// tail = tail->next;
		// tail->next = nullptr;
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.print();
	ll.insert_end(6);
	ll.print();
	ll.insert_end(10);
	ll.print();

	ll.insert_end(8);
	ll.print();

	ll.insert_end(15);
	ll.print();
	return 0;
}
