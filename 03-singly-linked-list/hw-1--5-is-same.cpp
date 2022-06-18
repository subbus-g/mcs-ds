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
	bool is_same(const LinkedList &other)
	{
		Node *ptr1, *ptr2;
		for (ptr1 = head, ptr2 = other.head; ptr1 && ptr2; ptr1 = ptr1->next, ptr2 = ptr2->next)
		{
			if (ptr1->data != ptr2->data)
			{
				return false;
			}
		}
		//true only if ptr1 and ptr2  reached to end and has nullptrs
		return !ptr1 && !ptr2;
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

	LinkedList lll;
	lll.insert_end(6);
	lll.insert_end(10);
	lll.insert_end(8);
	lll.insert_end(15);
	lll.insert_end(155);

	lll.print();

	cout << boolalpha << ll.is_same(lll) << endl;

	return 0;
}
