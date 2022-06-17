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
	Node *get_nth_item(int n)
	{
		int pos = 0;
		for (auto ptr = head; ptr; ptr = ptr->next)
		{
			// if current position is given n
			if (++pos == n)
			{
				return ptr;
			}
		}
		return nullptr;
	}
	int search(int value)
	{
		int index = 0;
		for (Node *ptr = head; ptr; ptr = ptr->next, index++)
		{
			if (ptr->data == value)
			{
				return index;
			}
		}
		return -1;
	}

	int improved_search(int value)
	{
		int index = 0;
		if (head->data == value)
		{
			return 0;
		}
		for (auto ptr = head; ptr->next; ptr = ptr->next, index++)
		{
			if (ptr->next->data == value)
			{
				swap(ptr->data, ptr->next->data);
				return index;
			}
		}
		return -1;
	}
	int improved_search_using_previous(int value)
	{
		int index = 0;
		for (Node *prev = nullptr, *curr = head; curr; prev = curr, curr = curr->next, index++)
		{

			if (curr->data == value)
			{
				if (!prev)
				{
					return 0;
				}
				swap(curr->data, prev->data);
				return index - 1;
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
	ll.insert_end(6);
	ll.insert_end(10);
	ll.insert_end(8);
	ll.insert_end(15);
	ll.print();

	// cout << ll.improved_search(6) << endl;
	// cout << ll.improved_search(15) << endl;

	cout << "improved search using prev pointer" << endl;
	cout << ll.improved_search_using_previous(6) << endl;
	cout << ll.improved_search_using_previous(15) << endl;

	return 0;
}
