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
	void add_num(LinkedList &another)
	{
		Node *ptr1, *ptr2;
		int carry = 0;
		// traverse until there is a number in both lists
		for (ptr1 = head, ptr2 = another.head; ptr1 && ptr2; ptr1 = ptr1->next, ptr2 = ptr2->next)
		{
			ptr1->data += ptr2->data + carry;
			carry = ptr1->data / 10;
			ptr1->data %= 10;
		}
		// if there is a carry and add it to the number before joining another list numbers
		if (ptr1 && carry)
		{
			ptr1->data += carry;
			carry = 0;
		}

		// traverse and add remaining elements of another to current list
		for (; ptr2; ptr2 = ptr2->next)
		{
			auto new_node = new Node(ptr2->data + carry);
			carry = 0;
			if (!head)
			{
				head = tail = new_node;
				continue;
			}
			tail->next = new_node;
			tail = new_node;
		}

		if (carry)
		{
			auto new_node = new Node(carry);
			tail->next = new_node;
			tail = new_node;
		}
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	// tc1
	{
		LinkedList list1;

		list1.insert_end(1);
		list1.insert_end(2);
		list1.insert_end(3);

		LinkedList list2;

		list2.insert_end(4);
		list2.insert_end(5);
		list2.insert_end(3);

		list1.print();
		list2.print();
		list1.add_num(list2);

		list1.print();
		string expected = "5 7 6";
		cout << expected << endl;
		cout << "----------------------------" << endl;
	}
	// tc2
	{
		LinkedList list1;

		list1.insert_end(1);
		list1.insert_end(2);
		list1.insert_end(9);

		LinkedList list2;

		list2.insert_end(3);
		list2.insert_end(5);
		list2.insert_end(4);

		list1.print();
		list2.print();
		list1.add_num(list2);

		list1.print();
		string expected = "4 7 3 1";
		cout << expected << endl;
		cout << "----------------------------" << endl;
	}
	// tc3
	{
		LinkedList list1;

		LinkedList list2;

		list2.insert_end(3);
		list2.insert_end(5);
		list2.insert_end(4);

		list1.print();
		list2.print();
		list1.add_num(list2);

		list1.print();
		string expected = "3 5 4";
		cout << expected << endl;
		cout << "----------------------------" << endl;
	}
	// tc4
	{
		LinkedList list1;
		list1.insert_end(9);
		list1.insert_end(6);
		list1.insert_end(5);

		LinkedList list2;
		list2.insert_end(8);
		list2.insert_end(7);
		list2.insert_end(6);
		list2.insert_end(4);
		list2.insert_end(5);
		list2.insert_end(7);
		list2.insert_end(8);
		list2.insert_end(9);

		list1.print();
		list2.print();
		list1.add_num(list2);

		list1.print();
		string expected = "7 4 2 5 5 7 8 9";
		cout << expected << endl;
		cout << "----------------------------" << endl;
	}
	// tc5
	{
		LinkedList list1;
		list1.insert_end(9);
		list1.insert_end(6);
		list1.insert_end(5);

		LinkedList list2;
		list2.insert_end(8);
		list2.insert_end(7);
		list2.insert_end(6);
		list2.insert_end(4);
		list2.insert_end(5);
		list2.insert_end(7);
		list2.insert_end(8);
		list2.insert_end(9);

		list1.print();
		list2.print();
		list2.add_num(list1);

		list2.print();
		string expected = "7 4 2 5 5 7 8 9";
		cout << expected << endl;
		cout << "----------------------------" << endl;
	}
	// // tc6
	// {
	// 	LinkedList list1;

	// 	list1.insert_end(1);
	// 	list1.insert_end(2);
	// 	list1.insert_end(9);

	// 	LinkedList list2;

	// 	list2.insert_end(3);
	// 	list2.insert_end(9);

	// 	list1.print();
	// 	list2.print();
	// 	list1.add_num(list2);

	// 	list1.print();
	// 	string expected = "4 1 0 1";
	// 	cout << expected << endl;
	// 	cout << "----------------------------" << endl;
	// }
	return 0;
}
