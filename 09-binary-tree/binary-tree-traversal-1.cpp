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
void print_inorder(Node *current)
{
	cout << current->left->val << endl;
	cout << (char)current->val << endl;
	cout << current->right->val;
}
int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	auto node2 = new Node(2);
	auto node3 = new Node(3);
	auto plus = new Node(node2, '+', node3);
	print_inorder(plus);
}
