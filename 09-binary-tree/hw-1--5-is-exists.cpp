#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
private:
	int data{};
	BinaryTree *left{};
	BinaryTree *right{};

public:
	BinaryTree(int data) : data(data)
	{
	}
	BinaryTree *current = this;

	void add(vector<int> values, vector<char> direction)
	{
		assert(values.size() == direction.size());
		// iterate on the path, create all necessary nodes
		for (int i = 0; i < (int)values.size(); ++i)
		{
			if (direction[i] == 'L')
			{
				if (!current->left)
					current->left = new BinaryTree(values[i]);
				else
					assert(current->left->data == values[i]);
				current = current->left;
			}
			else
			{
				if (!current->right)
					current->right = new BinaryTree(values[i]);
				else
					assert(current->right->data == values[i]);
				current = current->right;
			}
		}
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

	bool is_exists(int x)
	{
		bool exists = false;
		if (data == x)
			exists = true;
		else if (left)
		{
			exists = exists || left->is_exists(x);
		}
		else if (right)
		{
			exists = exists || right->is_exists(x);
		}
		return exists;
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	BinaryTree tree(1);
	tree.add({2, 4, 7}, {'L', 'L', 'L'});
	tree.add({2, 4, 8}, {'L', 'L', 'R'});
	tree.add({2, 5, 9}, {'L', 'R', 'R'});
	tree.add({3, 6, 15}, {'R', 'R', 'L'});

	tree.print_inorder();
	cout << endl;
	cout << "is 1 exists in the tree: " << boolalpha << tree.is_exists(1) << endl;
	cout << "is 15 exists in the tree: " << boolalpha << tree.is_exists(15) << endl;
	cout << "is 4 exists in the tree: " << boolalpha << tree.is_exists(4) << endl;
	cout << "is 69 exists in the tree: " << boolalpha << tree.is_exists(69) << endl;

	return 0;
}
