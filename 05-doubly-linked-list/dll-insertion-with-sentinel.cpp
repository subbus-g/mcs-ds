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
	DNode *header, *trailer;

public:
	DLinkedList()
	{
		header = new DNode(-1);
		trailer = new DNode(header, 9999);
		header->next = trailer;
	}
	void print()
	{
		if (header->next == trailer)
		{
			cout << "EMPTY" << endl;
			return;
		}
		for (auto ptr = header->next; ptr != trailer; ptr = ptr->next)
		{
			cout << ptr->data << " ";
		}
		cout << endl;
	}
	void insert_end(int x) // O(n)-time, O(1)-memory
	{
		auto new_node = new DNode(trailer->prev, x, trailer);
		trailer->prev->next = new_node;
		trailer->prev = new_node;
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	DLinkedList dll;
	dll.print();
	dll.insert_end(1);
	dll.print();
	dll.insert_end(2);
	dll.print();
	dll.insert_end(3);
	dll.print();
	dll.insert_end(4);
	dll.print();
	return 0;
}
