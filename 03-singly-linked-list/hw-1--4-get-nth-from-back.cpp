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
	int get_nth_from_back(int x)
	{
		int length = 0;
		for (auto ptr = head; ptr; ptr = ptr->next)
		{
			length++;
		}
		int index = 0;
		for (auto ptr = head; ptr; ptr = ptr->next, index++)
		{
			if (ptr->data == x)
			{
				// return 1-based index from end
				return length - index;
			}
		}
		return -1;
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.insert_end(1);
	ll.insert_end(2);
	ll.insert_end(3);
	ll.insert_end(4);
	ll.insert_end(5);
	ll.insert_end(6);
	ll.print();

	cout << ll.get_nth_from_back(1);

	return 0;
}
