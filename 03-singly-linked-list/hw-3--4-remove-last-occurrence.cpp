#include <iostream>
#include <unordered_set>
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
	// if there is only 1 occurence then delete itself
	void delete_last_occurrence(int key) // O(n) time - O(1) memory
	{
		cout << "key:" << key << endl;
		Node *last_occurred_node = nullptr;
		// traverse the list and assign the last_occured_node with latesh matched node
		// count the frequency of the key as well
		for (auto ptr = head; ptr; ptr = ptr->next)
		{
			if (ptr->data == key)
			{
				last_occurred_node = ptr;
			}
		}
		// if key is not there in the list;exit
		if (!last_occurred_node)
			return;

		// traverse list again and remove the last_occurred_node
		for (auto ptr = head; ptr && ptr->next; ptr = ptr->next)
		{
			if (head == last_occurred_node)
			{
				head = head->next;
				delete last_occurred_node;
				// cout << "tail for below list: " << tail->data << endl;
				return;
			}
			if (ptr->next == last_occurred_node)
			{
				ptr->next = ptr->next->next;
				if (tail == last_occurred_node)
				{
					tail = ptr;
				}
				delete last_occurred_node;
			}
		}
		// cout << "tail for below list: " << tail->data << endl;
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	// tc 1
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.print();
	list.delete_last_occurrence(1);
	list.print();
	cout << "----------------------------" << endl;

	// tc2
	LinkedList list_2;

	list_2.insert_end(1);
	list_2.insert_end(2);
	list_2.insert_end(3);
	list_2.insert_end(1);
	list_2.insert_end(4);
	list_2.print();
	list_2.delete_last_occurrence(1);
	list_2.print();

	cout << "----------------------------" << endl;

	// tc3
	LinkedList list_3;

	list_3.insert_end(1);
	list_3.insert_end(2);
	list_3.insert_end(3);
	list_3.insert_end(4);
	list_3.insert_end(1);
	list_3.print();
	list_3.delete_last_occurrence(1);
	list_3.print();

	cout << "----------------------------" << endl;

	// tc4
	LinkedList list_4;

	list_4.insert_end(1);
	list_4.insert_end(2);
	list_4.insert_end(3);
	list_4.insert_end(3);
	list_4.insert_end(3);
	list_4.insert_end(4);
	list_4.print();
	list_4.delete_last_occurrence(3);
	list_4.print();
	cout << "----------------------------" << endl;

	// tc5
	LinkedList list_5;

	list_5.insert_end(2);
	list_5.insert_end(1);
	list_5.insert_end(3);
	list_5.print();
	list_5.delete_last_occurrence(1);
	list_5.print();
	cout << "----------------------------" << endl;

	return 0;
}
