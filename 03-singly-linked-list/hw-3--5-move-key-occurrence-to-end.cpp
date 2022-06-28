#include <iostream>
#include <unordered_set>
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
	void move_key_occurance_to_end(int key)
	{
		cout << "key: " << key << endl;
		// cout << "tail for below list: " << tail->data << endl;
		Node *pre, *cur;
		pre = cur = head;
		auto old_tail = tail;
		while (cur != old_tail)
		{
			if (cur->data == key)
			{
				auto node_to_move = cur;
				if (node_to_move == head)
				{
					head = head->next;
					pre = cur = head;
				}
				else
				{
					cur = cur->next;
					pre->next = cur;
				}

				tail->next = node_to_move;
				tail = node_to_move;
				tail->next = nullptr;
			}
			else
			{
				pre = cur;
				cur = cur->next;
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
	list_1.insert_end(2);
	list_1.insert_end(4);
	list_1.insert_end(1);
	list_1.print();
	list_1.move_key_occurance_to_end(1);
	list_1.print();
	cout << "----------------------------" << endl;

	// tc2
	LinkedList list_2;
	list_2.insert_end(5);
	list_2.insert_end(2);
	list_2.insert_end(3);
	list_2.insert_end(2);
	list_2.insert_end(1);
	list_2.insert_end(1);
	list_2.print();
	list_2.move_key_occurance_to_end(1);
	list_2.print();
	cout << "----------------------------" << endl;

	// tc3
	LinkedList list_3;
	list_3.insert_end(1);
	list_3.insert_end(1);
	list_3.insert_end(1);
	list_3.insert_end(1);
	list_3.insert_end(1);
	list_3.insert_end(1);
	list_3.print();
	list_3.move_key_occurance_to_end(1);
	list_3.print();
	cout << "----------------------------" << endl;

	// tc4
	LinkedList list_4;
	list_4.insert_end(1);
	list_4.insert_end(2);
	list_4.insert_end(3);
	list_4.insert_end(1);
	list_4.insert_end(2);
	list_4.insert_end(4);
	list_4.insert_end(1);
	list_4.insert_end(7);
	list_4.insert_end(1);
	list_4.insert_end(8);
	list_4.insert_end(1);
	list_4.insert_end(1);
	list_4.print();
	list_4.move_key_occurance_to_end(1);
	list_4.print();
	cout << "----------------------------" << endl;

	return 0;
}
