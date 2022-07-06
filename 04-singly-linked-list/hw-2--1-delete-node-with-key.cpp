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
	void delete_first()
	{
		auto node_to_delete = head;
		head = head->next;
		delete node_to_delete;
	}
	void delete_last()
	{
		Node *ptr;
		for (ptr = head; ptr->next->next; ptr = ptr->next)
		{
		}
		auto node_to_delete = ptr->next;
		// ptr->next = ptr->next->next;
		tail = ptr;
		tail->next = nullptr;
		delete node_to_delete;
	}
	void delete_nth_node(int n)
	{
		if (n == 1)
		{
			delete_first();
			return;
		}
		int position = 0;
		Node *ptr;
		for (ptr = head; ptr && ++position != n - 1; ptr = ptr->next)
		{
		}
		auto node_to_delete = ptr->next;
		ptr->next = ptr->next->next;
		delete node_to_delete;
	}
	void delete_node_with_key(int value)//O(n)-time, O(1)-memory
	{
		int postion = 1;
		for (auto ptr = head; ptr; ptr = ptr->next, ++postion)
		{
			if (ptr->data == value)
			{
				delete_nth_node(postion);
				return;
			}
		}
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
	ll.insert_end(2);
	ll.insert_end(6);
	ll.print();
	ll.delete_node_with_key(2);
	ll.print();
}
