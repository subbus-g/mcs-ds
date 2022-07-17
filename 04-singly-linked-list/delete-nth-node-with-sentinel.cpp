#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next{};

	Node(int data) : data(data)
	{
	}
};
class LinkedList
{
private:
	Node *sentinel = new Node(-1);

public:
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
	}

	void delete_nth_node(int position)
	{
		Node *ptr;
		int i;
		for (i = 0, ptr = sentinel; i != position - 1; ++i, ptr = ptr->next)
		{
		}
		auto ntd = ptr->next;
		ptr->next = ptr->next->next;
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.print();
	ll.insert_end(1);
	ll.insert_end(2);
	ll.insert_end(3);
	ll.insert_end(4);
	ll.print();

	ll.delete_nth_node(1);
	ll.print();

	// ll.delete_nth_node(2);
	// ll.print();

	ll.delete_nth_node(3);
	ll.print();

	return 0;
}
