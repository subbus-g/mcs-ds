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
class DLinkedList
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
	void delete_all(int key)
	{
		DNode *cur;
		for (cur = head; cur; cur = cur->next)
		{
			if (cur->data == key)
			{
				auto node_to_delete = cur;
				if (node_to_delete == head)
				{
					head = head->next;
					head->prev = nullptr;
				}
				else if (node_to_delete == tail)
				{
					tail = tail->prev;
					tail->next = nullptr;
				}
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

	DLinkedList dll;
	dll.print();
	dll.insert_end(6);
	dll.insert_end(6);
	dll.insert_end(10);
	dll.insert_end(8);
	dll.insert_end(15);
	dll.insert_end(10);

	dll.print();

	dll.delete_all(6);
	dll.print();
	return 0;
}
