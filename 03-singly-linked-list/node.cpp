#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;

	Node(int data) : data(data)
	{
	}
};

int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	// creating 4 nodes
	Node *node1 = new Node(6);
	Node *node2 = new Node(10);
	Node *node3 = new Node(8);
	Node *node4 = new Node(15);

	// creating linking between them
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = nullptr;

	// accessing node 15;
	cout << node1->next->next->next->data << endl;
	cout << node2->next->next->data << endl;
	cout << node3->next->data << endl;
	cout << node4->data << endl;

	// we have four unique address here
	//but only last one is important
	printf("1.address of node pointer  : %u\n", &node1);
	printf("---------------------------------------\n");
	printf("2.address of the node      : %u\n", node1);
	printf("2.address of node->data    : %u\n", &(node1->data));
	printf("---------------------------------------\n");
	printf("3.address of node->next    : %u\n", &(node1->next));
	printf("---------------------------------------\n");
	printf("4.address of next node is  : %u\n", (node1->next));

	return 0;
}
