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
	void reverse_list_nodes() // O(n)-time, O(1)-memory
	{
		Node *curr, *prev, *backup;
		for (prev = head, curr = head->next; curr; prev = curr, curr = backup)
		{
			backup = curr->next;
			curr->next = prev;
		}
		head->next = nullptr;
		head = prev;
	}
	void reverse_list_nodes_using_tail() // O(n)-time, O(1)-memory
	{
		tail = head;
		auto prev = head;
		head = head->next;
		auto next = head;
		while (head)
		{
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		head = prev;
		tail->next = nullptr;
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
	ll.reverse_list_nodes_using_tail();
	ll.print();
	return 0;
}
