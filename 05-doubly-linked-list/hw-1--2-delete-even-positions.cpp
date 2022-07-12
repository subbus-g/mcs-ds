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
	void delete_even_positions()
	{
		int position = 1;
		for (auto cur = head; cur; cur = cur->next, position++)
		{
			if (position % 2)
			{
				continue;
			}
			auto node_to_delete = cur;
			if(node_to_delete==tail)
			{
				tail = tail->prev;
				tail->next = nullptr;
				break;
			}
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			cur = cur->prev;
			delete node_to_delete;
		}
		//tail integrity check
		cout << "tail for below list: " << tail->data << endl;
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

		list.insert_end(1);
		list.insert_end(2);
		list.insert_end(3);
		list.insert_end(4);
		list.insert_end(5);
		list.print();
		list.delete_even_positions();
		// some actions
		list.print();

		string expected = "1 3 5";
		cout << expected << " (expected)" << endl;
		cout << "----------------------------" << endl;
	}
	// tc2
	{
		LinkedList list;

		list.insert_end(1);
		list.insert_end(2);
		list.insert_end(3);
		list.insert_end(4);
		list.insert_end(5);
		list.insert_end(6);
		list.print();
		list.delete_even_positions();
		// some actions
		list.print();

		string expected = "1 3 5";
		cout << expected << " (expected)" << endl;
		cout << "----------------------------" << endl;
	}
	// tc3
	{
		LinkedList list;

		list.insert_end(1);
		list.insert_end(2);
		list.print();
		list.delete_even_positions();
		list.print();

		string expected = "1";
		cout << expected << " (expected)" << endl;
		cout << "----------------------------" << endl;
	}
	return 0;
}
