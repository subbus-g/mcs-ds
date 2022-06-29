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
	// O(n)-time,
	// O(n)-memory as new stack is created for every call
	int max(Node *curr = nullptr, bool is_head = true)
	{
		// if curr is nullptr
		if (!curr)
		{
			// if terminating null ptr
			if (!is_head)
				return INT_MIN;
			// initial call from main
			curr = head;
		}
		return std::max(curr->data, this->max(curr->next, false));
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
	cout << ll.max();
	return 0;
}
