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
	void insert_end(int x)
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
	// create new node node
	// assign next of new node to head
	// make the new node as head
	void insert_front(int x)
	{
		auto new_node = new Node(x);
		new_node->next = head;
		head = new_node;
	}
	// store the node to delete in new variable
	// point the head to its next node
	// delete the node using new variable
	void delete_front()//O(1)-time, O(1)-memory
	{
		auto node_to_delete = head;
		head = head->next;
		delete node_to_delete;
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.insert_end(6);
	ll.insert_end(10);
	ll.insert_end(8);
	ll.insert_end(15);
	ll.print();

	ll.insert_front(7);
	ll.insert_front(5);
	ll.insert_front(1);
	ll.print();

	ll.delete_front();
	ll.print();

	return 0;
}
