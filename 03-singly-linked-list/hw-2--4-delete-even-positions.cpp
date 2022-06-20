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
	// position starts with 1
	void delete_even_positions() // O(n)-time, O(1)-memory
	{
		// ptr stops at nullptr for even length
		// ptr stops at last node for odd length
		for (auto ptr = head; ptr && ptr->next; ptr = ptr->next)
		{
			auto node_to_delete = ptr->next;
			ptr->next = ptr->next->next;
			if(node_to_delete==tail)
			{
				tail = ptr;
			}
			delete node_to_delete;
		}
		//cout << "tail is " << tail->data << endl;
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
	// ll.insert_end(10);
	// ll.insert_end(5);
	// ll.insert_end(6);

	ll.print();
	ll.delete_even_positions();
	ll.print();
	return 0;
}
