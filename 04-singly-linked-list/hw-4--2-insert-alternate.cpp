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
	// O(max(n,m)) time - O(1) memory
	void insert_alternate(LinkedList &another)
	{
		auto ptr1 = head;
		auto ptr2 = another.head;
		// traverse both lists until anyone reached the end
		while (ptr1 && ptr2)
		{
			auto old_next = ptr1->next;
			auto node_to_insert = new Node(ptr2->data);
			ptr1->next = node_to_insert;
			node_to_insert->next = old_next;
			if (ptr1 == tail)
			{
				tail = node_to_insert;
			}
			ptr1 = old_next;
			ptr2 = ptr2->next;
		}
		// add the remaining elements of another if present
		for (; ptr2; ptr2 = ptr2->next)
		{
			auto node_to_insert = new Node(ptr2->data);
			if (!head)
			{
				head = tail = node_to_insert;
				continue;
			}
			tail->next = node_to_insert;
			tail = node_to_insert;
		}
		// integrity check for tail
		// cout << "tail for below list is: " << (tail?tail->data:0) << endl;
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

	LinkedList another_1;
	another_1.insert_end(4);
	another_1.insert_end(5);

	list_1.print();
	another_1.print();
	list_1.insert_alternate(another_1);
	list_1.print();
	cout << "----------------------------" << endl;

	// tc2
	LinkedList list_2;
	list_2.insert_end(1);
	list_2.insert_end(2);
	list_2.insert_end(3);

	LinkedList another_2;
	another_2.insert_end(4);

	list_2.print();
	another_2.print();
	list_2.insert_alternate(another_2);
	list_2.print();
	cout << "----------------------------" << endl;

	// tc3
	LinkedList list_3;
	list_3.insert_end(1);
	list_3.insert_end(2);
	list_3.insert_end(3);

	LinkedList another_3;
	another_3.insert_end(4);
	another_3.insert_end(5);
	another_3.insert_end(6);

	list_3.print();
	another_3.print();
	list_3.insert_alternate(another_3);
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

	// tc5
	LinkedList list_5;

	LinkedList another_5;
	another_5.insert_end(4);
	another_5.insert_end(5);
	another_5.insert_end(6);
	another_5.insert_end(7);

	list_5.print();
	another_5.print();
	list_5.insert_alternate(another_5);
	list_5.print();
	cout << "----------------------------" << endl;

	// tc6
	LinkedList list_6;
	list_6.insert_end(1);
	list_6.insert_end(2);
	list_6.insert_end(3);

	LinkedList another_6;
	list_6.print();
	another_6.print();
	list_6.insert_alternate(another_6);
	list_6.print();
	cout << "----------------------------" << endl;

	// tc7
	LinkedList list_7, another_7;
	list_7.print();
	list_7.insert_alternate(another_7);
	list_7.print();
	cout << "----------------------------" << endl;

	return 0;
}
