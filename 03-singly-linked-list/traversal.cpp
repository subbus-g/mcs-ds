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
			//if current position is given n
			if (++pos == n)
			{
				return ptr;
			}
		}
		return nullptr;
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

	auto found_node = ll.get_nth_item(1);
	cout << (found_node ? found_node->data : -1) << endl;

	found_node = ll.get_nth_item(2);
	cout << (found_node ? found_node->data : -1) << endl;

	found_node = ll.get_nth_item(3);
	cout << (found_node ? found_node->data : -1) << endl;

	found_node = ll.get_nth_item(4);
	cout << (found_node ? found_node->data : -1) << endl;

	found_node = ll.get_nth_item(5);
	cout << (found_node ? found_node->data : -1) << endl;
	return 0;
}
