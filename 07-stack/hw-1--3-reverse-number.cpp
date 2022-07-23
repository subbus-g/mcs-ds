#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Container = std::deque<T>>
void print_stack(std::stack<T, Container> stack)
{

	// template <typename T>
	// void print_stack(std::stack<T> stack){

	// Notice that we're working on a copy here. IMPORTANT
	std::cout << "stack of elements : [";
	while (!stack.empty())
	{
		T item = stack.top();
		std::cout << " " << item;
		stack.pop(); // Poping from a copy doesn't affect the original. We're good here.
	}
	std::cout << "]" << std::endl;
}
int reverse_number(int n)
{
	int reversed_number = 0;
	for (; n; n /= 10)
	{
		reversed_number = reversed_number * 10 + (n % 10);
	}
	return reversed_number;
}
int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	int n;
	cin >> n;

	cout << reverse_number(n);

	return 0;
}
