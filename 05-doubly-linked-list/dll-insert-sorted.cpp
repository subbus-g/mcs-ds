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
	void insert_front(int x)
	{
		if (!head)
		{
			head = tail = new DNode(x);
		}
		else
		{
			head = new DNode(x, head);
		}
	}
	void insert_sorted(int x)
	{
		if (!head)
		{
			head = tail = new DNode(x);
			return;
		}
		DNode *cur;
		for (cur = head; cur && (cur->data < x); cur = cur->next)
		{
		}
		if (cur == head)
		{
			head->prev = new DNode(x, head);
			head = head->prev;
			return;
		}
		if (!cur)
		{
			tail->next = new DNode(tail, x);
			tail = tail->next;
			return;
		}
		cur->prev = cur->prev->next = new DNode(cur->prev, x, cur);
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);
	{
		DLinkedList dll;
		dll.insert_sorted(10);
		dll.print();
		dll.insert_sorted(2);
		dll.print();
		dll.insert_sorted(30);
		dll.print();
		dll.insert_sorted(4);
		dll.print();
		dll.insert_sorted(1);
		dll.print();
	}
	cout << "-----------------------" << endl;
	return 0;
}
