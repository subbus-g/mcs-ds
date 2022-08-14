#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *left;
	Node *right;
	Node(int x) : left(nullptr), val(x), right(nullptr) {}
	Node(Node *left, int x, Node *right = nullptr) : left(left), val(x), right(right) {}
	Node(int x, Node *right) : left(nullptr), val(x), right(right) {}
};
void print_postorder(Node *root)
{
	if (!root)
		return;
	print_postorder(root->left);
	cout << root->val<<' ';
	print_postorder(root->right);
}
int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	auto node2 = new Node(2);
	auto node3 = new Node(3);
	auto node4 = new Node(4);
	auto plus = new Node(node2, '+', node3);
	auto asterisk = new Node(plus, '*', node4);
	print_postorder(asterisk);
}
