#include <iostream>
#include <cassert>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Stack
{
private:
	ListNode *head{};

public:
	Stack()
	{
	}
	bool isEmpty()
	{
		return !head;
	}

	void push(int x)
	{
		head = new ListNode(x, head);
	}
	int pop()
	{
		assert(!isEmpty());
		int ele = head->val;
		head = head->next;
		return ele;
	}
	int peek()
	{
		assert(!isEmpty());
		return head->val;
	}
	void display()
	{
		cout << "the stack is " << endl;
		for (auto ptr = head; ptr; ptr = ptr->next)
		{
			cout << ptr->val << endl;
		}
	}
	~Stack()
	{
		while (head)
		{
			ListNode *node_to_delete = head;
			cout << "destroyed:" << head->val << " " << endl;
			head = head->next;
			delete node_to_delete;
		}
	}
};
int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	Stack stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.display();
	cout << stk.peek() << endl;
	cout << stk.pop() << endl;
	stk.display();

	return 0;
}
