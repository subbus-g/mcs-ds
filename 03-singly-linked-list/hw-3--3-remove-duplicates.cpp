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
	void remove_duplicates_1() // O(n)-time, O(n)-memory
	{
		unordered_set<int> unique_numbers;
		Node *pre, *ptr;
		pre = ptr = head;
		while (ptr)
		{
			// if the number is duplicate
			if (unique_numbers.find(ptr->data) != end(unique_numbers))
			{
				// delete it
				auto node_to_delete = ptr;
				ptr = ptr->next;
				pre->next = ptr;
				if (tail == node_to_delete)
				{
					tail = pre;
				}
				delete node_to_delete;
			}
			// if the number is not duplicate
			else
			{
				// add it to the list of unique numbers
				unique_numbers.insert(ptr->data);
				pre = ptr;
				ptr = ptr->next;
			}
		}
		//tail check
		cout << "tail for below list is:" << tail->data << endl;
	}
	void remove_duplicates_2() // O(n^2)-time, O(1)-memory
	{
		// condition for i be not null for tc 3
		// after first iteration, there will be only one node
		// then i->next->next leads to seg fault
		// similarly i->next for tc 4, only 2 nodes left after 1st iteration
		// i->next->next leads to sig fault
		for (auto i = head; i && i->next && i->next->next; i = i->next)
		{
			// cout << "i is at " << i->data << endl;
			auto prev = i;
			for (auto j = i->next; j;)
			{
				// cout << "		j is at " << j->data << endl;
				if (i->data == j->data)
				{
					auto node_to_delete = j;
					j = j->next;
					prev->next = j;
					delete node_to_delete;
				}
				else
				{
					prev = j;
					j = j->next;
				}
			}
		}
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	// tc 1
	LinkedList ll_1;
	ll_1.insert_end(1);
	ll_1.insert_end(2);
	ll_1.insert_end(1);
	ll_1.insert_end(3);
	ll_1.insert_end(2);
	ll_1.insert_end(4);
	ll_1.insert_end(3);
	ll_1.insert_end(5);
	ll_1.insert_end(2);
	ll_1.print();
	ll_1.remove_duplicates_1();
	ll_1.print();
	cout << "----------------------------" << endl;

	// tc2
	LinkedList ll_2;
	ll_2.insert_end(1);
	ll_2.insert_end(2);
	ll_2.insert_end(3);
	ll_2.insert_end(4);
	ll_2.insert_end(5);
	ll_2.print();
	ll_2.remove_duplicates_1();
	ll_2.print();
	cout << "----------------------------" << endl;

	// tc3
	LinkedList ll_3;
	ll_3.insert_end(1);
	ll_3.insert_end(1);
	ll_3.insert_end(1);
	ll_3.print();
	ll_3.remove_duplicates_1();
	ll_3.print();
	cout << "----------------------------" << endl;

	// tc4
	LinkedList ll_4;
	ll_4.insert_end(1);
	ll_4.insert_end(2);
	ll_4.insert_end(1);
	ll_4.insert_end(1);
	ll_4.print();
	ll_4.remove_duplicates_1();
	ll_4.print();
	cout << "----------------------------" << endl;

	return 0;
}
