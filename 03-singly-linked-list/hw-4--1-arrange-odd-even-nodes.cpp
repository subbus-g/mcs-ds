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
	void arrange_odd_even_nodes()
	{
		Node *prev, *curr, *old_tail;
		int position;
		for (position = 0, prev = nullptr, curr = head, old_tail = tail; curr != old_tail;)
		{
			position++;
			// if the position is even
			if (position % 2 == 0)
			{
				auto node_to_move = curr;
				curr = curr->next;
				prev->next = curr;
				// move the even node to back
				tail->next = node_to_move;
				tail = node_to_move;
				tail->next = nullptr;
			}
			else
			{
				prev = curr;
				curr = curr->next;
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
	list_1.arrange_odd_even_nodes();
	list_1.print();
	cout << "----------------------------" << endl;

	// tc2
	LinkedList list_2;
	list_2.insert_end(1);
	list_2.insert_end(2);
	list_2.insert_end(3);
	list_2.print();
	list_2.arrange_odd_even_nodes();
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
	list_3.arrange_odd_even_nodes();
	list_3.print();
	cout << "----------------------------" << endl;

	// tc4
	LinkedList list_4;
	list_4.insert_end(11);
	list_4.insert_end(33);
	list_4.insert_end(55);
	list_4.insert_end(4);
	list_4.insert_end(50);
	list_4.insert_end(17);
	list_4.insert_end(8);
	list_4.print();
	list_4.arrange_odd_even_nodes();
	list_4.print();
	cout << "----------------------------" << endl;

	return 0;
}
