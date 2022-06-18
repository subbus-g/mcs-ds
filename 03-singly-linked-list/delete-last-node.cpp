#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;

	Node(int data) : data(data)
	{
	}
};
class LinkedList
{
private:
	Node *head{};
	Node *tail{};

public:
	void print()
	{
		for (auto ptr = head; ptr; ptr = ptr->next)
		{
			cout << ptr->data << " ";
		}
		cout << endl;
	}
	void insert_end(int x) // O(n)-time, O(1)-memory
	{
		if (!head)
		{
			head = new Node(x);
			tail = head;
			head->next = nullptr;
			return;
		}
		auto new_node = new Node(x);
		tail->next = new_node;
		tail = tail->next;
		tail->next = nullptr;
	}
	void delete_last()
	{
		Node *ptr;
		for (ptr = head; ptr->next->next;ptr=ptr->next)
		{

		}
		auto node_to_delete = ptr->next;
		//ptr->next = ptr->next->next;
		tail = ptr;
		tail->next = nullptr;
		delete node_to_delete;
	}

};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.insert_end(6);
	ll.insert_end(10);
	ll.insert_end(8);
	ll.insert_end(15);
	ll.print();
	ll.delete_last();
	ll.print();
	ll.delete_last();
	ll.print();

	ll.delete_last();
	ll.print();

	ll.delete_last();
	ll.print();

	return 0;
}
