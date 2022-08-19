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

	void insert(int target)
	{
		if (!left && target < data)
		{
			left = new BinarySearchTree(target);
			return;
		}
		else if (!right && target > data)
		{
			right = new BinarySearchTree(target);
			return;
		}
		else if (target < data)
		{
			left->insert(target);
		}
		else if (target > data)
		{
			right->insert(target);
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
