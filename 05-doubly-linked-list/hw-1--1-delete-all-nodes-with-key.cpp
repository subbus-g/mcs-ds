#include <iostream>
using namespace std;

struct DNode
{
	int data;
	DNode *prev, *next;
	DNode() : prev(nullptr), data(-1), next(nullptr)
	{
	}
	DNode(int data) : prev(nullptr), data(data), next(nullptr)
	{
	}
	DNode(DNode *prev, int data) : prev(prev), data(data), next(nullptr)
	{
	}
	DNode(int data, DNode *next) : prev(), data(data), next(next)
	{
	}
	DNode(DNode *prev, int data, DNode *next) : prev(prev), data(data), next(next)
	{
	}
};
class LinkedList
{
private:
	DNode *head{};
	DNode *tail{};

public:
	void print()
	{
		if (!head)
		{
			cout << "EMPTY" << endl;
			return;
		}
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
			head = tail = new DNode(x);
		}
		else
		{
			tail->next = new DNode(tail, x);
			tail = tail->next;
		}
	}
	void delete_all_nodes_with_key(int key)
	{
		DNode *cur;
		for (cur = head; cur; cur = cur->next)
		{
			// if key is found
			// arrange the links first
			// then delete the key nodek
			if (cur->data == key)
			{
				auto node_to_delete = cur;
				// if key is in head position
				if (node_to_delete == head)
				{
					if (!head->next)
					{
						head = tail = nullptr;
						break;
					}
					head = head->next;
					head->prev = nullptr;
					cur = new DNode(-11, head);
				}
				// if key is in tail positon
				else if (node_to_delete == tail)
				{
					tail = tail->prev;
					tail->next = nullptr;
					break;
				}
				// if key is in middle position
				else
				{
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
				}
				delete node_to_delete;
			}
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
		LinkedList list;
		list.print();

		list.insert_end(1);
		list.insert_end(2);
		list.insert_end(5);
		list.insert_end(4);
		list.insert_end(5);
		list.insert_end(4);
		list.insert_end(4);
		list.delete_all_nodes_with_key(5);

		list.print();

		string expected = "1 2 4 4 4";
		cout << expected << " (expected)" << endl;
		cout << "----------------------------" << endl;
	}
	// tc2
	{
		LinkedList list;
		list.print();

		list.insert_end(1);
		list.insert_end(1);

		list.delete_all_nodes_with_key(1);

		list.print();

		string expected = "EMPTY";
		cout << expected << " (expected)" << endl;
		cout << "----------------------------" << endl;
	}
	// tc3
	{
		LinkedList list;
		list.print();

		list.insert_end(1);
		list.insert_end(2);
		list.insert_end(5);
		list.insert_end(4);
		list.insert_end(4);
		list.insert_end(4);
		list.insert_end(4);
		list.delete_all_nodes_with_key(4);

		list.print();

		string expected = "1 2 5";
		cout << expected << " (expected)" << endl;
		cout << "----------------------------" << endl;
	}
	// tc4
	{
		LinkedList list;
		list.print();

		list.insert_end(1);
		list.insert_end(2);
		list.insert_end(5);
		list.insert_end(4);
		list.delete_all_nodes_with_key(7);

		list.print();

		string expected = "1 2 5 4";
		cout << expected << " (expected)" << endl;
		cout << "----------------------------" << endl;
	}
	return 0;
}
