#include <iostream>
#include <assert.h>
using namespace std;

class Vector
{
private:
	int *arr = nullptr;
	int size, capacity;
	void expand_capacity()
	{
		capacity *= 2;
		int *temp = arr;
		arr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		delete[] temp;
	}

public:
	Vector() : size(0), capacity(0)
	{
	}
	Vector(int size) : size(size), capacity(size)
	{

		if (size < 1)
		{
			size = 1;
		}
		arr = new int[size];
	}
	int get(int idx)
	{
		assert(idx >= 0 && idx <= size);
		return arr[idx];
	}
	void set(int idx, int val)
	{
		assert(idx >= 0 && idx <= size);
		arr[idx] = val;
	}
	int find(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value)
			{
				return i;
			}
		}
		return -1;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int get_front()
	{
		return arr[0];
	}
	int get_back()
	{
		return arr[size - 1];
	}
	// highly unoptimal approach
	// takes O(size) space but O(1) amortized time for 1 push back operation
	void push_back(int value)
	{
		// if block is executed less often now
		if (size == capacity)
		{
			expand_capacity();
		}
		arr[size++] = value;
	}
	// takes O(size) time
	void insert(int idx, int value)
	{
		if (size == capacity)
		{
			expand_capacity();
		}
		size++;

		// // create a hole at idx
		// for (int i = size ; i > idx; i--)
		// {
		// 	// pull the value from preceeding location
		// 	arr[i]=arr[i-1]
		// }

		// create a hole at idx
		for (int i = size - 1; i >= idx; i--)
		{
			// push the current value to succeeding location
			arr[i + 1] = arr[i];
		}

		// fill the hole with given value
		arr[idx] = value;
	}
	int pop(int idx)
	{
		//push the element out of the array
		for (int i = idx; i < size - 1; i++)
		{
			swap(arr[i], arr[i + 1]);
		}
		size--;
		return arr[size];
	}

	~Vector()
	{
		delete[] arr;
		arr = nullptr; // resetting
	}
};
int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	int n = 5;
	Vector v(n);
	v.set(0, 4);
	v.set(1, 0);
	v.set(2, 1);
	v.set(3, 2);
	v.set(4, 3);

	v.print();
	cout << v.pop(2) << endl;
	v.print();
	return 0;
}
