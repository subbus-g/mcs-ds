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

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	auto node_4 = new Node(4);
	auto node_7 = new Node(7);
	auto node_8 = new Node(8);

	auto node_5 = new Node(5, node_7);
	auto node_6 = new Node(node_8, 6);

	auto node_2 = new Node(node_4, 2, node_5);
	auto node_3 = new Node(3, node_6);

	auto root = new Node(node_2, 1, node_3);

	cout << root->left->right->right->val << "\n"; // 7
	cout << node_2->right->right->val << "\n";	   // 7
	cout << node_5->right->val << "\n";			   // 7
	cout << node_7->val << "\n";				   // 7

	cout << root->right->right->val << "\n";	   // 6
	cout << root->right->right->left->val << "\n"; // 8
	cout << root->right->right->right << "\n";	   // 0x00
}
