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
	void insert_alternate(LinkedList &another)
	{
		auto ptr1 = head;
		auto ptr2 = another.head;
		while (ptr1 && ptr2)
		{
			auto old_next = ptr1->next;
			auto node_to_insert = new Node(ptr2->data);
			ptr1->next = node_to_insert;
			node_to_insert->next = old_next;
			tail = node_to_insert;
			ptr1 = old_next;
			ptr2 = ptr2->next;
		}
		if (ptr2)
		{
			while (ptr2)
			{
				auto new_node = new Node(ptr2->data);
				tail->next = new_node;
				tail = new_node;
				ptr2 = ptr2->next;
			}
		}
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	// tc 1
	LinkedList list_1;
	list_1.insert_end(1);
	list_1.insert_end(2);
	list_1.insert_end(3);
	list_1.insert_end(4);
	list_1.print();
	// list_1.arrange_odd_even_nodes();
	list_1.print();
	cout << "----------------------------" << endl;

	// tc2
	LinkedList list_2;
	list_2.insert_end(1);
	list_2.insert_end(2);
	list_2.insert_end(3);
	list_2.print();
	// list_2.arrange_odd_even_nodes();
	list_2.print();
	cout << "----------------------------" << endl;

	// tc3
	LinkedList list_3;
	list_3.insert_end(1);
	list_3.insert_end(2);
	list_3.insert_end(3);
	list_3.insert_end(4);
	list_3.insert_end(5);
	list_3.insert_end(6);
	list_3.insert_end(7);
	list_3.print();
	// list_3.arrange_odd_even_nodes();
	list_3.print();
	cout << "----------------------------" << endl;

	// tc4
	LinkedList list_4;
	list_4.insert_end(1);
	list_4.insert_end(2);
	list_4.insert_end(3);

	LinkedList another_4;
	another_4.insert_end(4);
	another_4.insert_end(5);
	another_4.insert_end(6);
	another_4.insert_end(7);

	list_4.print();
	another_4.print();
	list_4.insert_alternate(another_4);
	list_4.print();
	cout << "----------------------------" << endl;
	return 0;
}
