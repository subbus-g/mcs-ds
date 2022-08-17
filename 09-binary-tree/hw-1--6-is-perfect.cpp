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
		BinaryTree *current = this;
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
	int tree_height()
	{
		// height of the empty tree is -1
		int left_height = -1, right_height = -1;

		if (left)
			left_height = left->tree_height();
		if (right)
			right_height = right->tree_height();
		return 1 + max(left_height, right_height);
	}
	bool is_perfect(int h = -1)
	{

		// initial call
		if (h == -1)
		{
			// assign h with the height of the tree
			h = tree_height();
		}

		// actual checking for perfectness

		// if there is only 1 child
		if (left && !right || !left && right)
		{
			// it is not perfect
			return false;
		}
		// if the node is leaf then it should present at height 0 to be perfect
		else if (!left && !right)
		{
			if (h == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		// in other cases, we can determines perfectness of the tree by
		// determining the perfectness of its left subtree and its right subtree
		else
		{
			return left->is_perfect(h - 1) && right->is_perfect(h - 1);
		}
	}
};
int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	BinaryTree tree(1);

	cout << "tree.is_perfect() == 1 " << tree.is_perfect() << endl;

	tree.add({2}, {'L'});
	tree.add({3}, {'R'});

	cout << "tree.is_perfect() == 1 " << tree.is_perfect() << endl;

	tree.add({2, 4, 7}, {'L', 'L', 'L'});
	tree.add({2, 4, 8}, {'L', 'L', 'R'});
	tree.add({2, 5, 9}, {'L', 'R', 'R'});
	tree.add({3, 6, 15}, {'R', 'R', 'L'});

	cout << "tree.is_perfect() == 0 " << tree.is_perfect() << endl;

	tree.add({2, 5, 13}, {'L', 'R', 'L'});
	tree.add({3, 6, 12}, {'R', 'R', 'R'});
	tree.add({3, 14, 15}, {'R', 'L', 'L'});
	tree.add({3, 14, 16}, {'R', 'L', 'R'});

	cout << "tree.is_perfect() == 1 " << tree.is_perfect() << endl;
}
