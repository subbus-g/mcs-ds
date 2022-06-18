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

public:
	void print() // O(n)-time, O(1)-memory
	{
		for (auto ptr = head; ptr; ptr = ptr->next)
		{
			cout << ptr->data << " ";
		}
		cout << endl;
	}
	void add_element(int value) // O(1)-time, O(1)-memory
	{
		auto new_node = new Node(value);
		new_node->next = head;
		head = new_node;
	}
	Node *get_tail()//O(n)-time, O(1)-memory
	{
		Node *ptr;
		//traverse upto the lastnode
		for (ptr = head; ptr->next; ptr = ptr->next)
			;
		return ptr;
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.add_element(1);
	ll.add_element(2);
	ll.add_element(3);
	ll.print();
	cout << "The value at Tail node is: " << ll.get_tail()->data;
	return 0;
}
