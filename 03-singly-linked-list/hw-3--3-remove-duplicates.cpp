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
	void remove_duplicates() // O(n)-time, O(n)-memory
	{
		unordered_set<int> unique_numbers;
		Node *pre, *ptr;
		pre = ptr = head;
		while (ptr)
		{
			//if the number is duplicate
			if (unique_numbers.find(ptr->data) != end(unique_numbers))
			{
				//delete it
				auto node_to_delete = ptr;
				ptr = ptr->next;
				pre->next = ptr;
				delete node_to_delete;
			}
			//if the number is not duplicate
			else
			{
				//add it to the list of unique numbers
				unique_numbers.insert(ptr->data);
				pre = ptr;
				ptr = ptr->next;
			}
		}
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	LinkedList ll;
	ll.print();

	//tc 1
	ll.insert_end(1);
	ll.insert_end(2);
	ll.insert_end(1);
	ll.insert_end(3);
	ll.insert_end(2);
	ll.insert_end(4);
	ll.insert_end(3);
	ll.insert_end(5);
	ll.insert_end(2);

	//tc 2
	// ll.insert_end(1);
	// ll.insert_end(2);
	// ll.insert_end(3);
	// ll.insert_end(4);
	// ll.insert_end(5);

	//tc 3
	// ll.insert_end(1);
	// ll.insert_end(1);
	// ll.insert_end(1);


	ll.print();
	ll.remove_duplicates();
	ll.print();
	return 0;
}
