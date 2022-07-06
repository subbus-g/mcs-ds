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
	int length{};

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
		length++;
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
	void left_rotate(int k)
	{
		//remove un necessary cycles
		k %= length;
		int i;
		Node *head_backup, *ptr;
		head_backup = head;
		for (i = 1, ptr = head; i < k; i++, ptr = ptr->next)
		{
		}
		head = ptr->next;
		ptr->next = nullptr;
		tail->next = head_backup;
		tail = ptr;
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.print();
	// ll.insert_end(1);
	// ll.insert_end(2);
	// ll.insert_end(3);
	// ll.insert_end(4);
	ll.insert_end(6);
	ll.insert_end(10);
	ll.insert_end(8);
	ll.insert_end(15);
	ll.print();
	ll.left_rotate(3);
	// ll.left_rotate(1);
	// ll.left_rotate(2);
	ll.print();
	return 0;
}
