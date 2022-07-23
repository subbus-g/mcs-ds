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
string reverse_subwords(string line)
{
	string reversed{};
	stack<int> stk;
	for (auto &c : line)
	{
		if (c != ' ')
		{
			stk.push(c);
			continue;
		}
		while (!stk.empty())
		{
			reversed += stk.top();
			stk.pop();
		}
		reversed += ' ';
	}
	while (!stk.empty())
	{
		reversed += stk.top();
		stk.pop();
	}
	return reversed;
}
int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	string line;
	getline(cin, line);
	cout << line << endl;
	cout << reverse_subwords(line) << "\n";

	return 0;
}
