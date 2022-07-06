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
			cout << ptr<<"-"<<ptr->data <<"->"<< ",";
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
	void swap_head_tail()
	{
		Node *ptr;
		for (ptr = head; ptr->next->next; ptr = ptr->next)
		{
		}
		ptr->next = head;
		tail->next = head->next;
		head->next = nullptr;
		swap(head, tail);
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.print();
	ll.insert_end(1);
	ll.insert_end(2);
	ll.insert_end(3);
	ll.insert_end(4);
	ll.print();
	ll.swap_head_tail();
	ll.print();
	return 0;
}
