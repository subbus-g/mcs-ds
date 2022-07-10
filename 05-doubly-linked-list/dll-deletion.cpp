#include <iostream>
using namespace std;

struct DNode
{
	int data;
	DNode *prev, *next;
	DNode() : prev(nullptr), data(0), next(nullptr)
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
	DNode *sentinel = new DNode(-1);

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
	void delete_front()
	{
		if (!head)
		{
			return;
		}
		if (!head->next)
		{
			delete head;
			head = tail = nullptr;
			return;
		}
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	void delete_end()
	{
		if (!head)
		{
			return;
		}
		if (!head->next)
		{
			delete tail;
			head = tail = nullptr;
			return;
		}
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	DNode *delete_link(DNode *cur)
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		auto node_to_delete = cur;
		cur = cur->prev;
		delete node_to_delete;
		return cur;
	}
	void delete_node_with_key(int value)
	{
		if (!head)
		{
			return;
		}
		DNode *ptr;
		for (ptr = head; ptr && (ptr->data != value); ptr = ptr->next)
		{
		}
		if (!ptr)
		{
			return;
		}
		if (ptr == head)
		{
			delete_front();
			return;
		}
		if (ptr == tail)
		{
			delete_end();
			return;
		}
		ptr = delete_link(ptr);
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
	dll.insert_end(10);
	dll.insert_end(8);
	dll.insert_end(15);
	dll.print();
	// dll.delete_end();
	// dll.print();
	// dll.delete_end();
	// dll.print();
	// dll.delete_end();
	// dll.print();
	// dll.delete_end();
	// dll.print();
	// dll.delete_end();
	// dll.print();

	dll.delete_node_with_key(6);
	dll.print();
	dll.delete_node_with_key(8);
	dll.print();
	dll.delete_node_with_key(15);
	dll.print();
	dll.delete_node_with_key(10);
	dll.print();
	dll.delete_node_with_key(10);
	dll.print();
	return 0;
}
