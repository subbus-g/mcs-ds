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
	cout << node4->data;

	// Node* head=node1;
	// cout<<&head;
	printf("%u", &node1);
	cout << &node1 << endl;
	cout << "node 1 pointer address  " << std::dec << &node1 << endl;
	cout << "address node pointing to  " << node1 << endl;
	cout << "address of node1->data  " << &(node1->data) << endl;
	cout << "address of node1->next`  " << &(node1->next) << endl;

	printf("address of node1->data is %u\n", &(node1->data));
	printf("address of node1->next is %u\n", &(node1->next));

	// int arr[4] = {1, 2, 3, 4};
	// printf("%u\n", arr);
	// printf("%u\n", &arr[0]);
	// printf("%u\n", &arr[1]);
	return 0;
}