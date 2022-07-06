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
	Node *head{nullptr};
	Node *tail{nullptr};

public:
	void print()
	{
		for (auto ptr = head; ptr; ptr = ptr->next)
		{
			cout << ptr->data << " ";
		}
		cout << endl;
		// cout << "tail: " << tail->data << endl;
	}
	void insert_sorted(int x) // O(n)-time, O(1)-memory
	{
		Node *prev = head;
		Node *curr = head;
		auto new_node = new Node(x);

		// finding required position for insertion
		for (; (curr && curr->data < x); prev = curr, curr = curr->next)
		{
		}
		// insertion at front
		if (prev == curr && curr == head)
		{
			new_node->next = prev;
			if (!head)
				tail = new_node;
			head = new_node;
		}
		// insertion at remaining positions
		else
		{
			prev->next = new_node;
			new_node->next = curr;
			if (!curr)
				tail = new_node;
		}
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.insert_sorted(10);
	ll.print();
	ll.insert_sorted(2);
	ll.print();
	ll.insert_sorted(30);
	ll.print();
	ll.insert_sorted(4);
	ll.print();
	ll.insert_sorted(1);
	ll.print();
	return 0;
}
