#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char val;
	Node *left;
	Node *right;
	Node(char x) : left(nullptr), val(x), right(nullptr) {}
	Node(Node *left, char x, Node *right = nullptr) : left(left), val(x), right(right) {}
	Node(char x, Node *right) : left(nullptr), val(x), right(right) {}
};
class BinaryTree
{
	int val;
	BinaryTree *left{};
	BinaryTree *right{};

public:
	BinaryTree(int val) : val(val)
	{
	}
	void print_inorder()
	{
		if (left)
			left->print_inorder();
		cout << val << " ";
		if (right)
			right->print_inorder();
	}
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
					assert(current->left->val == values[i]);
				current = current->left;
			}
			else
			{
				if (!current->right)
					current->right = new BinaryTree(values[i]);
				else
					assert(current->right->val == values[i]);
				current = current->right;
			}
		}
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
	tree.add({3, 6, 10}, {'R', 'R', 'L'});

	tree.print_inorder();
	// 7 4 8 2 5 9 1 3 10 6

	return 0;
}
