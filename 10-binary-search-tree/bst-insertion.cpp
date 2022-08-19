#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

class BinarySearchTree
{
private:
	int data{};
	BinarySearchTree *left{};
	BinarySearchTree *right{};

public:
	BinarySearchTree(int data) : data(data)
	{
	}

	void print_inorder()
	{
		if (left)
			left->print_inorder();
		cout << data << " ";
		if (right)
			right->print_inorder();
	}
	////////////////////////////////////////////

	//initial call with 1 element as root
	//so null root check is not required
	void insert(int target)
	{
		//if the given element is less than root's element
		if (target < data)
		{
			//if the current tree has no left subtree
			if (!left)
			{
				//create one and stop
				left = new BinarySearchTree(target);
				return;
			}
			//else insert in the left subTree
			else
			{
				left->insert(target);
			}
		}
		// if the given element is greather than root's element
		else if (target > data)
		{
			//if the current tree has no right subTree
			if (!right)
			{
				//create one and stop
				right = new BinarySearchTree(target);
				return;
			}
			//else insert in the right subTree
			else
			{
				right->insert(target);
			}
		}
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	BinarySearchTree tree(50);
	tree.insert(20);
	tree.insert(45);
	tree.insert(70);
	tree.insert(73);
	tree.insert(35);
	tree.insert(15);
	tree.insert(60);

	cout << "expected: "
		 << "15 20 35 45 50 60 70 73 " << endl;
	cout << "actual:   ";

	tree.print_inorder();
	cout << endl;

	return 0;
}
